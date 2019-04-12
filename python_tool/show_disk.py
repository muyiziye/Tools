#!/usr/bin/env python

import subprocess

def get_disk_space(user):
        run_watch = subprocess.Popen("du -sh /home/%s " % user,
                shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        ret, err_msg = run_watch.communicate()
        return ret

def get_all_disk_space():
        run_watch = subprocess.Popen("df -h /home/",
                shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        ret, err_msg = run_watch.communicate()
        return ret

if "__main__" == __name__:
        welcome_file = "/etc/motd"
        welcome_str = "+++++++++++++++++++++++++++++++++++++++\nName\t\tdisk Space\n--------------------------------\n"
        user_list = ["liuyang", "user2"]
        for user in user_list:
                disk_space = get_disk_space(user)
                welcome_str += user + "\t\t" + disk_space.split("\t")[0] + "\n"
        welcome_str += "=============================\n"
        all_space = get_all_disk_space()
        home_info = all_space.split()
        home_show = "Sized\tAvail\tUsed\tUsed%\n"
        home_show += "%s\t%s\t%s\t%s" % (home_info[-5], home_info[-3], home_info[-4], home_info[-2])
        welcome_str += home_show
        info_to_team = "\nWhen the disk space is NOT enough, pls help to clean your work space\n++++++++++++++++++++++++++++++++++++++++\n"
        welcome_str += info_to_team
        print welcome_str
        fh = open(welcome_file, 'w')
        fh.write(welcome_str)
        fh.close()
