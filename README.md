# XJTU_openjudge
This is a tiny openjudge system written in bash shell and C++, which is created for cs major freshmen in XJTU's honor class.

### Using_Guide

this is a readme file for Online Judge.


show: 

Commond 'show' will dIsplay a question list or the details of a question.

	show list
	Display the question list.
	
	show [questionID]
	Display the details of a question.
	#questionID:the name of the question

for example:
	*[shx@dachuang-oj ~]\$* show list
	A
	B
	C
	*[shx@dachuang-oj ~]$* show A
	add two numbers(integer) together
	example:
	input:1 2
    output:3



submit:

Commond 'submit' will submit your answer to the Online Judge.After that,you will receive a score 
in seconds if submission succeeded.Otherwise,you will receive a submission failed message(or maybe
no message)if you failed to submit your answer.
	

	submit [path] [questionID]
	Submit your file to OJ.
	#path:the location of your file you want to submit
		(both absolute path and relative path are ok)
	#questionID:the name of the question

for example:
	*[shx@dachuang-oj ~]\$* submit shx.cpp A
	*[shx@dachuang-oj ~]$*
	Your Submission to question A :

	test1:Accepted!
	test2:Accepted!
	test3:Accepted!
	Total Score:100.0/100