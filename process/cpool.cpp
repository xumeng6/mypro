#include<thread>
//CThreadManage
//CThreadManage的功能非常简单，其提供最简单的方法，其类定义如下：i
class CThreadPool;
class CJob;

class CThreadManage
{
	private:
		CThreadPool*    m_Pool;
		int          m_NumOfThread;
	protected:
	public:
		void     SetParallelNum(int num);
		CThreadManage();
		CThreadManage(int num);
		virtual ~CThreadManage();

		void    Run(CJob* job,void* jobdata);
		void    TerminateAll(void);
};
//其中m_Pool指向实际的线程池；m_NumOfThread是初始创建时候允许创建的并发的线程个数。另外Run和TerminateAll方法也非常简单，只是简单的调用CThreadPool的一些相关方法而已。其具体的实现如下:
CThreadManage::CThreadManage(){
	m_NumOfThread = 10;
	m_Pool = new CThreadPool(m_NumOfThread);
}
CThreadManage::CThreadManage(int num){
	m_NumOfThread = num;
	m_Pool = new CThreadPool(m_NumOfThread);
}
CThreadManage::~CThreadManage(){
	if(NULL != m_Pool)
		delete m_Pool;
}
void CThreadManage::SetParallelNum(int num){
	m_NumOfThread = num;
}
void CThreadManage::Run(CJob* job,void* jobdata){
	m_Pool->Run(job,jobdata);
}
void CThreadManage::TerminateAll(void){
	m_Pool->TerminateAll();
}

//CThread
//CThread 类实现了对Linux中线程操作的封装，它是所有线程的基类，也是一个抽象类，提供了一个抽象接口Run，所有的CThread都必须实现该Run方法。CThread的定义如下所示：
class CThread
{
	private:
		int          m_ErrCode;
		Semaphore    m_ThreadSemaphore;  //the inner semaphore, which is used to realize
		unsigned     long m_ThreadID;
		bool         m_Detach;       //The thread is detached
		bool         m_CreateSuspended;  //if suspend after creating
		char*        m_ThreadName;
		ThreadState m_ThreadState;      //the state of the thread
	protected:
		void     SetErrcode(int errcode){m_ErrCode = errcode;}
		static void* ThreadFunction(void*);
	public:
		CThread();
		CThread(bool createsuspended,bool detach);
		virtual ~CThread();
		virtual void Run(void) = 0;
		void     SetThreadState(ThreadState state){m_ThreadState = state;}

		bool     Terminate(void);    //Terminate the threa
		bool     Start(void);        //Start to execute the thread
		void     Exit(void);
		bool     Wakeup(void);

		ThreadState  GetThreadState(void){return m_ThreadState;}
		int      GetLastError(void){return m_ErrCode;}
		void     SetThreadName(char* thrname){strcpy(m_ThreadName,thrname);}
		char*    GetThreadName(void){return m_ThreadName;}
		int      GetThreadID(void){return m_ThreadID;}

		bool     SetPriority(int priority);
		int      GetPriority(void);
		int      GetConcurrency(void);
		void     SetConcurrency(int num);
		bool     Detach(void);
		bool     Join(void);
		bool     Yield(void);
		int      Self(void);
};
//线程的状态可以分为四种，空闲、忙碌、挂起、终止(包括正常退出和非正常退出)。由于目前Linux线程库不支持挂起操作，因此，我们的此处的挂起操作类似于暂停。如果线程创建后不想立即执行任务，那么我们可以将其“暂停”，如果需要运行，则唤醒。有一点必须注意的是，一旦线程开始执行任务，将不能被挂起，其将一直执行任务至完毕。
//线程类的相关操作均十分简单。线程的执行入口是从Start()函数开始，其将调用函数ThreadFunction，ThreadFunction再调用实际的Run函数，执行实际的任务。

//CThreadPool
//CThreadPool是线程的承载容器，一般可以将其实现为堆栈、单向队列或者双向队列。在我们的系统中我们使用STL Vector对线程进行保存。CThreadPool的实现代码如下：
class CThreadPool
{
	friend class CWorkerThread;
	private:
	unsigned int m_MaxNum;   //the max thread num that can create at the same time
	unsigned int m_AvailLow; //The min num of idle thread that shoule kept
	unsigned int m_AvailHigh;    //The max num of idle thread that kept at the same time
	unsigned int m_AvailNum; //the normal thread num of idle num;
	unsigned int m_InitNum;  //Normal thread num;
	protected:
	CWorkerThread* GetIdleThread(void);

	void    AppendToIdleList(CWorkerThread* jobthread);
	void    MoveToBusyList(CWorkerThread* idlethread);
	void    MoveToIdleList(CWorkerThread* busythread);

	void    DeleteIdleThread(int num);
	void    CreateIdleThread(int num);
	public:
	CThreadMutex m_BusyMutex;    //when visit busy list,use m_BusyMutex to lock and unlock
	CThreadMutex m_IdleMutex;    //when visit idle list,use m_IdleMutex to lock and unlock
	CThreadMutex m_JobMutex; //when visit job list,use m_JobMutex to lock and unlock
	CThreadMutex m_VarMutex;

	CCondition       m_BusyCond; //m_BusyCond is used to sync busy thread list
	CCondition       m_IdleCond; //m_IdleCond is used to sync idle thread list
	CCondition       m_IdleJobCond;  //m_JobCond is used to sync job list
	CCondition       m_MaxNumCond;

	vector<CWorkerThread*>   m_ThreadList;
	vector<CWorkerThread*>   m_BusyList;     //Thread List
	vector<CWorkerThread*>   m_IdleList; //Idle List

	CThreadPool();
	CThreadPool(int initnum);
	virtual ~CThreadPool();

	void    SetMaxNum(int maxnum){m_MaxNum = maxnum;}
	int     GetMaxNum(void){return m_MaxNum;}
	void    SetAvailLowNum(int minnum){m_AvailLow = minnum;}
	int     GetAvailLowNum(void){return m_AvailLow;}
	void    SetAvailHighNum(int highnum){m_AvailHigh = highnum;}
	int     GetAvailHighNum(void){return m_AvailHigh;}
	int     GetActualAvailNum(void){return m_AvailNum;}
	int     GetAllNum(void){return m_ThreadList.size();}
	int     GetBusyNum(void){return m_BusyList.size();}
	void    SetInitNum(int initnum){m_InitNum = initnum;}
	int     GetInitNum(void){return m_InitNum;}

	void    TerminateAll(void);
	void    Run(CJob* job,void* jobdata);
};

CThreadPool::CThreadPool()
{
	m_MaxNum = 50;
	m_AvailLow = 5;
	m_InitNum=m_AvailNum = 10 ;
	m_AvailHigh = 20;

	m_BusyList.clear();
	m_IdleList.clear();
	for(int i=0;i<m_InitNum;i++){
		CWorkerThread* thr = new CWorkerThread();
		thr->SetThreadPool(this);
		AppendToIdleList(thr);
		thr->Start();
	}
}

CThreadPool::CThreadPool(int initnum)
{
	assert(initnum>0 && initnum<=30);
	m_MaxNum   = 30;
	m_AvailLow = initnum-10>0?initnum-10:3;
	m_InitNum=m_AvailNum = initnum ;
	m_AvailHigh = initnum+10;

	m_BusyList.clear();
	m_IdleList.clear();
	for(int i=0;i<m_InitNum;i++){
		CWorkerThread* thr = new CWorkerThread();
		AppendToIdleList(thr);
		thr->SetThreadPool(this);
		thr->Start();       //begin the thread,the thread wait for job
	}
}

CThreadPool::~CThreadPool()
{
	TerminateAll();
}

void CThreadPool::TerminateAll()
{
	for(int i=0;i < m_ThreadList.size();i++) {
		CWorkerThread* thr = m_ThreadList[i];
		thr->Join();
	}
	return;
}

CWorkerThread* CThreadPool::GetIdleThread(void)
{
	while(m_IdleList.size() ==0 )
		m_IdleCond.Wait();

	m_IdleMutex.Lock();
	if(m_IdleList.size() > 0 )
	{
		CWorkerThread* thr = (CWorkerThread*)m_IdleList.front();
		printf("Get Idle thread %dn",thr->GetThreadID());
		m_IdleMutex.Unlock();
		return thr;
	}
	m_IdleMutex.Unlock();

	return NULL;
}

//add an idle thread to idle list
void CThreadPool::AppendToIdleList(CWorkerThread* jobthread)
{
	m_IdleMutex.Lock();
	m_IdleList.push_back(jobthread);
	m_ThreadList.push_back(jobthread);
	m_IdleMutex.Unlock();
}

//move and idle thread to busy thread
void CThreadPool::MoveToBusyList(CWorkerThread* idlethread)
{
	m_BusyMutex.Lock();
	m_BusyList.push_back(idlethread);
	m_AvailNum--;
	m_BusyMutex.Unlock();

	m_IdleMutex.Lock();
	vector<CWorkerThread*>::iterator pos;
	pos = find(m_IdleList.begin(),m_IdleList.end(),idlethread);
	if(pos !=m_IdleList.end())
		m_IdleList.erase(pos);
	m_IdleMutex.Unlock();
}

void CThreadPool::MoveToIdleList(CWorkerThread* busythread)
{
	m_IdleMutex.Lock();
	m_IdleList.push_back(busythread);
	m_AvailNum++;
	m_IdleMutex.Unlock();

	m_BusyMutex.Lock();
	vector<CWorkerThread*>::iterator pos;
	pos = find(m_BusyList.begin(),m_BusyList.end(),busythread);
	if(pos!=m_BusyList.end())
		m_BusyList.erase(pos);
	m_BusyMutex.Unlock();

	m_IdleCond.Signal();
	m_MaxNumCond.Signal();
}

//create num idle thread and put them to idlelist
void CThreadPool::CreateIdleThread(int num)
{
	for(int i=0;i<num;i++){
		CWorkerThread* thr = new CWorkerThread();
		thr->SetThreadPool(this);
		AppendToIdleList(thr);
		m_VarMutex.Lock();
		m_AvailNum++;
		m_VarMutex.Unlock();
		thr->Start();       //begin the thread,the thread wait for job
	}
}

void CThreadPool::DeleteIdleThread(int num)
{
	printf("Enter into CThreadPool::DeleteIdleThreadn");
	m_IdleMutex.Lock();
	printf("Delete Num is %dn",num);
	for(int i=0;i<num;i++){
		CWorkerThread* thr;
		if(m_IdleList.size() > 0 ){
			thr = (CWorkerThread*)m_IdleList.front();
			printf("Get Idle thread %dn",thr->GetThreadID());
		}

		vector<CWorkerThread*>::iterator pos;
		pos = find(m_IdleList.begin(),m_IdleList.end(),thr);
		if(pos!=m_IdleList.end())
			m_IdleList.erase(pos);
		m_AvailNum--;
		printf("The idle thread available num:%d n",m_AvailNum);
		printf("The idlelist              num:%d n",m_IdleList.size());
	}
	m_IdleMutex.Unlock();
}

void CThreadPool::Run(CJob* job,void* jobdata)
{
	assert(job!=NULL);

	//if the busy thread num adds to m_MaxNum,so we should wait
	if(GetBusyNum() == m_MaxNum)
		m_MaxNumCond.Wait();

	if(m_IdleList.size()<m_AvailLow)
	{
		if(GetAllNum()+m_InitNum-m_IdleList.size() < m_MaxNum )
			CreateIdleThread(m_InitNum-m_IdleList.size());
		else
			CreateIdleThread(m_MaxNum-GetAllNum());
	}

	CWorkerThread*  idlethr = GetIdleThread();
	if(idlethr !=NULL)
	{
		idlethr->m_WorkMutex.Lock();
		MoveToBusyList(idlethr);
		idlethr->SetThreadPool(this);
		job->SetWorkThread(idlethr);
		printf("Job is set to thread %d n",idlethr->GetThreadID());
		idlethr->SetJob(job,jobdata);
	}
}
//在CThreadPool中存在两个链表，一个是空闲链表，一个是忙碌链表。Idle链表中存放所有的空闲进程，当线程执行任务时候，其状态变为忙碌状态，同时从空闲链表中删除，并移至忙碌链表中。在CThreadPool的构造函数中，我们将执行下面的代码:
for(int i=0;i<m_InitNum;i++)
{
	CWorkerThread* thr = new CWorkerThread();
	AppendToIdleList(thr);
	thr->SetThreadPool(this);
	thr->Start();       //begin the thread,the thread wait for job
}
