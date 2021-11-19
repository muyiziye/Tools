#!/usr/bin/env bash
# add by liuyang in 2021/11/10

# get the baned ip list
ip_list=`sudo fail2ban-client status sshd | tail -n 1`
ip_list=`echo $ip_list | awk -F: '{printf $2}' | sed "s/ \t//g"`

if [[ x$ip_list == x"" ]];then
	exit 0
fi

# add baned ip to hosts.deny file
for ip_ban in $ip_list
do
	ip_is_ban=`cat /etc/hosts.deny | grep $ip_ban | wc -l`
	
	if [[ x$ip_is_ban == x0 ]];then
		echo "$ip_ban will be added into hosts.deny"
		echo "sshd:$ip_ban" >> /etc/hosts.deny
	fi
done

