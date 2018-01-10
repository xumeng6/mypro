set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/vundle/
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/nerdtree'
Plugin 'jistr/vim-nerdtree-tabs'
Plugin 'Xuyuanp/nerdtree-git-plugin'
Plugin 'ctrlpvim/ctrlp.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'Raimondi/delimitMate'			  "Automatic completion symbol
Plugin 'Mizuchi/STL-Syntax'               "Enhanced c/c++ syntax highlighting
Plugin 'octol/vim-cpp-enhanced-highlight' "Enhanced c++ syntax highlighting
Plugin 'Chiel92/vim-autoformat'     "Format code plugin
Plugin 'Lokaltog/vim-powerline'     "Beautify status bar
Plugin 'Yggdroot/indentLine'        "Indent indicator 
"Plugin 'elzr/vim-json'              "JSON auxiliary plugin

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

"VIM configuration option

syntax enable
set nu!                             
set backspace=indent,eol,start      
set nowrap                          
set ruler                           "Always display the cursor position in the lower right corner
set tabstop=4                       
set softtabstop=4
set shiftwidth=4                   
set textwidth=79
set autoindent
set fileformat=unix
"set guifont=consolas:h14 
"set expandtab
"set showcmd 

set fileencodings=utf-8,ucs-bom,utf-16,gbk,big5,gb18030,latin1,cp936,gb2312
"set encoding=utf-8
"set langmenu=zh_CN.UTF-8
"language message zh_CN.UTF-8

nmap <C-h> <C-W>h                   "Set Ctrl-h to split screen toggle left  Normal mode effective
nmap <C-l> <C-W>l                   
nmap <C-k> <C-W>k                   
nmap <C-j> <C-W>j                  


"YouCompleteMe configuration option
let g:ycm_server_python_interpreter = '/usr/bin/python'
let g:ycm_global_ycm_extra_conf='~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
"let g:ycm_key_invoke_completion="
set completeopt=longest,menu
autocmd InsertLeave * if pumvisible() == 0|pclose|endif
let g:ycm_collect_identifiers_from_tags_files=1
let g:ycm_min_num_of_chars_for_completion=2
let g:ycm_cache_omnifunc=0          
let g:ycm_seed_identifiers_with_syntax=1
let g:ycm_complete_in_comments = 1
let g:ycm_complete_in_strings = 1
let g:ycm_key_invoke_completion = '<c-l>'
nmap gd :YcmCompleter GoToDefinition<CR>
"Set GD to jump to define shortcut key
nmap gc :YcmCompleter GoToDeclaration<CR>
"Set GC to jump to declare shortcut key
"let g:ycm_python_binary_path = '/usr/bin/python3'

"NERDTree configuration option
map <F2> :NERDTreeTabsToggle<CR>    
let g:nerdtree_tabs_autoclose=1     
let g:nerdtree_tabs_autofind=1      

"delimitMate configuration option
let delimitMate_expand_cr=1

"autoformat configuration option
let g:formatterpath = ['/usr/bin']   "Set astyle path
let g:formatdef_harttle = '"astyle --style=allman"'
let g:formatters_c = ['harttle']    
let g:formatters_cpp = ['harttle'] 
nmap <F3> :Autoformat<CR>           "Set <F3> format current file

"vim-powerline configuration option
let g:Powerline_sysbols = 'fancy'
set laststatus=2

"indengLine configuration option
let g:indentLine_enable=1


