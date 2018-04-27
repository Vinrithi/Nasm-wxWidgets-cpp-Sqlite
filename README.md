# Nasm-wxWidgets-CPP-Sqlite
This is a project about connecting and sqlite database with assembly language i.e. NASM. C++ is used to create the interface for easier manipulation of the database, using  wxWidgets. 

For all the details about the project, check out this 7 page pdf file https://drive.google.com/file/d/1SYuMpJT16ZDF73SJrxLXVH8tcp0LMmZD/view?usp=sharing that is a description of what the project entails.

Here, I will give a short summary of how to do it.

Software Requirements

Linux OS -- nasm runs in linux. I use Ubuntu
Code editor (codeblocks) -optional  -- use Ubuntu software downloader to download
wxWidgets -- https://wiki.wxwidgets.org/Installing_and_configuring_under_Ubuntu
sqlite browser -- it is a windows application that is used to view sqlite databases. However, it can run in Linux if you run it using win application. http://sqlitebrowser.org/

How it works.

Please make sure that you have sqlite3.h file in /usr/bin/. If not, please use the command 'sudo apt-get install sqlite3 libsqlite3-dev' without the ''. You can also download it outside and copy it to the bin folder.

The backend i.e. connecting and executing the queries in the database are done using assembly language. 

The front end i.e. the interface which you use to enter the data, do updates, see tarnsaction status and even view the generated sql query is done using C++ and wxWidgets. C++ will capture the data, form it into an sql query and then pass it to NASM. NASM will then do execution in the database and return the status of the transaction, which is then displayed on the interface.

Please note that this project is not viable for doing serious database coding. It is merely for learning purposes but if you are good enough you can make a full system using assembly language. 
