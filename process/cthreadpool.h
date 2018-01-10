#include<semaphore.h>
using namespace::std;
class CThreadManage{
	private:
		CThreadPool* m_pool;
		int m_Numofthread;
	public:
		CThreadManage();
		CThreadManage(int num);
		virtual ~CThreadManage();

		void SetParallelNum(int num);
		void Run(CJob* job,void* jobdata);
		void TerminateAll(void);
};
CThreadManage::CThreadManage(){
	m_Numofthread=10;
	m_pool=new CThreadPool(m_Numofthread);
}
CThreadManage::CThreadManage(int num){
	m_Numofthread=num;
	m_pool=new CThreadPool(m_Numofthread);
}
CThreadManage::~CThreadManage(){
	if(NULL!=m_pool)
		delete m_pool;
}
void CThreadManage::SetParallelNum(int num){
	m_Numofthread=num;
}
void CThreadManage::Run(CJob* job,void* jobdata){
	m_pool->Run(job,jobdata);
}
void CThreadManage::TerminateAll(void){
	m_pool->TerminateAll();
}
class CThread{
	private:
		int m_ErrCode;
		Semaphore m_ThreadSemaphore;
		unsigned long m_ThreadID;
		bool m_Detach;
		bool m_CreateSuspended;
		char* m_ThreadName;
		ThreadState m_ThreadState;

};

