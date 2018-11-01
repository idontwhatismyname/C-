# WSL入门

## 安装wsl
我们可以从Windows商店中去下载Ubuntu18.04以获取并安装wsl  
<font size=2>*注：下载可能会出现问题 需要多重试几次*</font>
## 初识wsl
<font size=2>*注：我也是刚开始用 先跳过这part 尚待完善*</font>

### wsl是什么？
#### 根据维基百科的定义
>适用于 Linux 的 Windows 子系统（英语：Windows Subsystem for Linux，简称WSL）是一个为在Windows 10上能够原生运行Linux二进制可执行文件（ELF格式）的兼容层。它是由微软与Canonical公司合作开发，目标是使纯正的Ubuntu 14.04/18.04, OpenSUSE, Kali Linux和Debian映像能下载和解压到用户的本地计算机，并且映像内的工具和实用工具能在此子系统上原生运行。
>WSL提供了一个微软开发的Linux兼容内核接口（不包含Linux代码），来自Ubuntu的用户模式二进制文件在其上运行。
>该子系统不能运行所有Linux软件，例如那些图形用户界面，以及那些需要未实现的Linux内核服务的软件。不过，这可以用在外部X服务器上运行的图形X窗口系统缓解。

### 更换api源
* 先备份内置数据源  
```
cp /etc/apt/sources.list /etc/apt/sources.list_backup
```
进去阿里云数据源官网`http://mirrors.aliyun.com/`  
寻找`ubuntu`的`帮助`以更换数据源
* 编辑阿里云数据源
```
sudo vi /etc/apt/sources.list
```
在wsl的vim中清空原文件的内容  
<font size=2>*注：vim的基本命令：`i` 进入插入模式 `：wq` 保存后退出*</font>   
将以下代码编辑进去
```
deb http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
```
* 更新配置
```
sudo apt-get update
sudo apt-get upgrade
```
* 下载基本编译器
```
sudo apt-get install build-essential
```
<font size=2>*To be continued*</font>