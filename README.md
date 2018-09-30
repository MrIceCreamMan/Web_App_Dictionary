# SuperDictionary
Web App - Customize Dictionary

Dependency: install cmake from https://cmake.org/

How to build and run the web app:

1:	open terminal and clone this repository "git clone https://github.com/MrIceCreamMan/Web_App_Dictionary.git"

2: 	go to this repository directory "cd Web_App_Dictionary"

3:	make a new clean directory"mkdir build"

4:	go to the directory you just created"cd build"

5:	use cmake to generate make file with command "cmake -DMAIN=ON .."

6:	use make to compile the executable file. Just type "make"

7:	start the server by type "./SuperDictionary"

8:	open your browser and type the url "http://www.localhost:8080", and now you can use the web app




How to use the web app - Super Dictionary:

There are 3 functions.

1: You can search a word:
	Type in a word you want to search in the field "Enter the word to search",
	and then click the "search" button next to it. Then, the word you just typed in 
	will be displayed. Under it, you will see either a list of its definitoins or
	a text saying "no definiton found"

2: You can add word and definiton:
	Type in a word in field "Enter the word to add" and type in the definition in
	field "Enter the definition", and then click the "add" button. You will see a 
	text saying "Definitoin added". If you type in either only the word or only the definition, and click the "add", your input will be ignored. You must fill both fields and then click "add" button.

3:	Top 10 most search words will be dispalyed:
	Every time you search a existing word, the dictionary will update the search 
	frequecy of that word. The top 10 most frequently searched word will be dispalyed
	in order.
