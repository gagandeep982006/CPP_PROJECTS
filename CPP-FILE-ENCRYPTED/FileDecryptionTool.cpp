#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<dirent.h>

using namespace std;

int main(){

    //checking dontdeletit.txt exist or not
    int checkpoint = 0;
    DIR* dir;
    struct dirent* ent;
    dir = opendir(".");
    while((ent = readdir(dir)) != NULL){
        if(string(ent->d_name) == string("dontdeletit.txt")){
            checkpoint = 1;
        }
    }
    //closing the directory
    closedir(dir);

    try{
        if(checkpoint == 1){
            //storing the vector here
            vector<string> specialsign{"CDEFGHIJSTUVWXY","Rm4","33Wohj","M19","98643bjh"};
            vector<int> dontdeletitdata;
            vector<string> filename;

            //storing the dontdeletit data in a vector
            ifstream read("dontdeletit.txt");
            int i = 0;
            int data;
            while(!read.eof()){
                read>>data;
                dontdeletitdata.push_back(data);
                i++;
            }
            dontdeletitdata.pop_back();
            //closinng the file
            read.close();

            //storing the filename which we have to store in a vector
            string data2;
            for(read.open("filename.txt");!read.eof();i++){
                getline(read,data2);
                filename.push_back(data2);
            }
            //closing the file;
            read.close();
            filename.pop_back();
            filename.pop_back();

            //writing the code to corect the encripted file
            int j = 0;
            while(filename.size() > j){
                //corected the coded file
                read.open(filename[j],ios::in|ios::binary);
                ofstream write("try.txt",ios::out|ios::binary);
                while(getline(read,data2)){
                    // getline(read,data2);
                    int position  = data2.find(specialsign[dontdeletitdata[j]]);
                    int length = specialsign[dontdeletitdata[j]].size();
                    if(position >=0){
                        data2.erase(position,length);
                    }
                    reverse(data2.begin(),data2.end());
                    write<<data2<<endl;
                }
                //closing the files
                read.close();
                write.close();

                //now writing the data to original file
                read.open("try.txt",ios::in|ios::binary);
                write.open(filename[j],ios::out|ios::binary);
                while(getline(read,data2)){
                    // getline(read,data2);
                    write<<data2<<endl;
                }
                //closing the file
                read.close();
                write.close();

                //increasing the j
                j++;

            }

            //now deleting the file;
            remove("dontdeletit.txt");
            remove("filename.txt");
            remove("try.txt");

        }

        else{
            cout<<"work is already done!!"<<endl;
        }
    }
    
    catch(int n){}

    return 0;
}
