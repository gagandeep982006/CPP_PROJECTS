                                                           # FILE-ENCRYPTED-IN-CPP
This will encrypted your jpg,pdf,jpeg,png,gif files in current directory of the user 
->How encrypted.cpp file work 
1.first it take the names of the files from your directory 
2. Then it seprate the png,jpg,jpeg,gif,pdf files and store it in txt file 
3.then it open file one by one in binary format 
4.then it reverse the each line and add select a random string from the string array and add it to a random position 
5.then it store the index of that random string in a txt file.

->now how solution.cpp file work 
1.first of all it read the file name from the txt file and read the first index stroed in txt file 
2.then it open that file in a binary format and copy all data to another file and remove the random added strings 
3.then it reverse the each line and then it past the data in original file 
4.and that is repeated for all files and how that it work
