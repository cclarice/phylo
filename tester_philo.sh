#!/bin/bash

clear
echo -e "\033[1m\033[32m"
echo -e \
"      ::::::::  :::      ::: :::           
      :+:   :+: :+:          :+:           
      +:+   +:+ +:+:+:+  +:+ +:+   +:+:+:+ 
      :#+   :#+ :#+  :#+ :#+ :#+  :#+   :#+
      +#++#++#  +#+  +#+ +#+ +#+  +#+   +#+
      #+#       #+#  #+# #+# #+#  #+#   #+#
      ###       ###  ### ###  ###  ####### 
                                           
      Tester by cclarice        Jul 17 2021
\033[0m"
sleep 0.75s
cd philo
echo -e "\033[33mSTART - make re\033[0m"
make re
echo -e "\033[33mEND   - make re\033[0m"
if [[ -a philo ]]
then

echo -e \
"\033[33mSTART - Test with 1 800 200 200, the philosopher should not eat and should die!\033[0m"
./philo 1 800 200 200
echo -e \
"\033[33mEND   - Test with 1 800 200 200, the philosopher should not eat and should die!\033[0m"
echo -e "\033[35mCheck Program and press ENTER to continue...\033[0m"
read

echo -e \
"\033[33mSTART - Test with 5 800 200 200, no one should die!\033[0m"
./philo 5 800 200 200 20
echo -e \
"\033[33mEND   - Test with 5 800 200 200 [20], no one should die!\033[0m"
echo -e "\033[35mCheck Program and press ENTER to continue...\033[0m"
read

echo -e \
"\033[33mSTART - Test with 5 800 200 200 7, no one should die and the simulation should stop when all the philosopher has eaten at least 7 times each.\033[0m"
./philo 5 800 200 200 7 > output.txt
cat output.txt
grep "1 is eating" output.txt
echo -ne "\033[36m1 times eaten: \033[0m"
grep "1 is eating" output.txt | wc -l
grep "2 is eating" output.txt
echo -ne "\033[36m2 times eaten: \033[0m"
grep "2 is eating" output.txt | wc -l
grep "3 is eating" output.txt
echo -ne "\033[36m3 times eaten: \033[0m"
grep "3 is eating" output.txt | wc -l
grep "4 is eating" output.txt
echo -ne "\033[36m4 times eaten: \033[0m"
grep "4 is eating" output.txt | wc -l
grep "5 is eating" output.txt
echo -ne "\033[36m5 times eaten: \033[0m"
grep "5 is eating" output.txt | wc -l
rm output.txt
echo -e \
"\033[33mEND   - Test with 5 800 200 200 7, no one should die and the simulation should stop when all the philosopher has eaten at least 7 times each.\033[0m"
echo -e "\033[35mCheck Program and press ENTER to continue...\033[0m"
read

echo -e \
"\033[33mSTART - Test with 4 410 200 200 [100], no one should die!\033[0m"
./philo 4 410 200 200 100
echo -e \
"\033[33mEND   - Test with 4 410 200 200 [100], no one should die!\033[0m"
echo -e "\033[35mCheck Program and press ENTER to continue...\033[0m"
read

echo -e \
"\033[33mSTART - Test with 4 310 200 100 [100], a philosopher should die!\033[0m"
./philo 4 310 200 100 100
echo -e \
"\033[33mEND   - Test with 4 310 200 100 [100], a philosopher should die!\033[0m"
echo -e "\033[35mCheck Program and press ENTER to continue...\033[0m"
read

echo -e \
"\033[33mSTART - Test with 2 philosophers and check the different times (a death delayed by more than 10 ms is unacceptable).\033[0m"
echo ./philo 2 130 60 60 5
./philo 2 130 60 60 5
echo ./philo 2 120 60 60 5
./philo 2 120 60 60 5
echo ./philo 2 120 80 80 5
./philo 2 120 80 80 5
echo ./philo 2 170 80 80 5
./philo 2 170 80 80 5
echo -e \
"\033[33mEND   - Test with 2 philosophers and check the different times (a death delayed by more than 10 ms is unacceptable).\033[0m"
echo -e "\033[35mCheck Program and press ENTER to continue...\033[0m"
read

else
echo -e "\033[31mMakefile ERROR!!!"
fi