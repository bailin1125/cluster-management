
##这个程序的目的就是监控每个用户的使用情况

import os
import time

USER_NUM=51
TIME_SLEEP=30
file_name="gpu_User.txt"

def get_user_dict(name):
    key_list=[]
    value_list=[]
    user_dict={}
    print(os.getcwd())
    fo=open(name,"rt",encoding="GB18030")
    for line in fo:
        #try:
        #    ##line.decode("utf-8")
        #except:
        #    print(str(line))
        key_list.append(line.split()[0])
        value_list.append(line.split()[1])
    fo.close()
    for i in range(len(key_list)):
        user_dict[key_list[i]]=value_list[i]
    return user_dict

##作用：根据用户的姓名，补充到用户用时列表中
def check_user(user_dict,file_name,sleep_time):
    ##先监控，然后读旧的文件，最后产生新的文件
    i=0
    time_save=[0]*USER_NUM    
    real_user=[]
    real_user=list(user_dict.keys())
    for i in range(len(user_dict.keys())):
        num=int(os.popen("qstat -u "+real_user[i]+"  | grep  "+'" R "'+"| wc -l").read())
        ##print("qstat -u "+"  |grep  "+real_user[i]+" wc -l")
        ##获得了这个用户有几个任务在跑
        #print(num)
        if(num == 0):
            continue
        result=os.popen("qstat -u "+real_user[i]+"  | grep  "+'" R "').read()        
        ##print(result)
        #time.sleep(2)
        for line in result.splitlines():
            #print(str(line))
            ##time.sleep(20)
            if(real_user[i] not in line):
                continue
            #print(line.strip().split()[5])
            time_save[i]=int(line.strip().split()[5])+time_save[i]
    i=0
    try:
        old=open(file_name,"r")
        for line in old:
            time_save[i]=time_save[i]+float(line)
            i=i+1
        old.close()
        ##然后开始产生新的文件
        out=open(file_name,"wt")
        for tt in time_save:
            print(str(tt/3600*TIME_SLEEP))
            out.write(str(tt/3600*TIME_SLEEP))
            out.write("\n")
        out.close()
        print("-----------------\n")
        print("休眠30s")
        time.sleep(sleep_time)
    except:
        ##读旧文件失败就直接产生新的文件
        ##然后开始产生新的文件
        out=open(file_name,"wt")
        for tt in time_save:
            out.write(str(tt/3600*TIME_SLEEP))
            out.write("\n")
        out.close()
        print("-----------------\n")
        print("休眠30s")
        time.sleep(sleep_time)        
def main():
    print("该程序可以监控集群使用情况\n")
    user_dict=get_user_dict(file_name)
    print(user_dict)
    while(1):                
        check_user(user_dict,"gpu_check.txt",TIME_SLEEP)
if __name__=="__main__":
    main()