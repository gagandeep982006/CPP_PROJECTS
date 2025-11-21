#include<iostream>
#include<vector>
#include<string>
#include<windows.h>
#include<map>

using namespace std;

class typewriter{
    vector<char> typedata;
    vector<int> typedata2;
    multimap<string,char> keydata{{"0",0x30},{"1",0x31},{"2",0x32},{"3",0x33},
    {"4",0x34},{"5",0x35},{"6",0x36},{"7",0x37},{"8",0x38},{"9",0x39},
    {"a",0x41},{"b",0x42},{"c",0x43},{"d",0x44},{"e",0x45},{"f",0x46},
    {"g",0x47},{"h",0x48},{"i",0x49},{"j",0x4A},{"k",0x4B},{"l",0x4C},
    {"m",0x4D},{"n",0x4E},{"o",0x4F},{"p",0x50},{"q",0x51},{"r",0x52},
    {"s",0x53},{"t",0x54},{"u",0x55},{"v",0x56},{"w",0x57},{"x",0x58},
    {"y",0x59},{"z",0x5A},{" ",VK_SPACE},{"/",VK_OEM_2},{"*",VK_MULTIPLY},
    {"+",VK_ADD},{"-",VK_OEM_MINUS},{";",VK_OEM_1},{"=",VK_OEM_PLUS},{",",VK_OEM_COMMA},
    {".",VK_OEM_PERIOD},{"`",VK_OEM_3},{"\\",VK_OEM_5},{"'",VK_OEM_7},{"[",VK_OEM_4},
    {"]",VK_OEM_6},{"A",VK_CAPITAL},{"A",0x41},{"A",VK_CAPITAL},
    {"B",VK_CAPITAL},{"B",0x42},{"B",VK_CAPITAL},{"C",VK_CAPITAL},{"C",0x43},{"C",VK_CAPITAL},
    {"D",VK_CAPITAL},{"D",0x44},{"D",VK_CAPITAL},{"E",VK_CAPITAL},{"E",0x45},{"E",VK_CAPITAL},
    {"F",VK_CAPITAL},{"F",0x46},{"F",VK_CAPITAL},{"G",VK_CAPITAL},{"G",0x47},{"G",VK_CAPITAL},
    {"H",VK_CAPITAL},{"H",0x48},{"H",VK_CAPITAL},{"I",VK_CAPITAL},{"I",0x49},{"I",VK_CAPITAL},
    {"J",VK_CAPITAL},{"J",0x4A},{"J",VK_CAPITAL},{"K",VK_CAPITAL},{"K",0x4B},{"K",VK_CAPITAL},
    {"L",VK_CAPITAL},{"L",0x4C},{"L",VK_CAPITAL},{"M",VK_CAPITAL},{"M",0x4D},{"M",VK_CAPITAL},
    {"N",VK_CAPITAL},{"N",0x4E},{"N",VK_CAPITAL},{"O",VK_CAPITAL},{"O",0x4F},{"O",VK_CAPITAL},
    {"P",VK_CAPITAL},{"P",0x50},{"P",VK_CAPITAL},{"Q",VK_CAPITAL},{"Q",0x51},{"Q",VK_CAPITAL},
    {"R",VK_CAPITAL},{"R",0x52},{"R",VK_CAPITAL},{"S",VK_CAPITAL},{"S",0x53},{"S",VK_CAPITAL},
    {"T",VK_CAPITAL},{"T",0x54},{"T",VK_CAPITAL},{"U",VK_CAPITAL},{"U",0x55},{"U",VK_CAPITAL},
    {"V",VK_CAPITAL},{"V",0x56},{"V",VK_CAPITAL},{"W",VK_CAPITAL},{"W",0x57},{"W",VK_CAPITAL},
    {"X",VK_CAPITAL},{"X",0x58},{"X",VK_CAPITAL},{"Y",VK_CAPITAL},{"Y",0x59},{"Y",VK_CAPITAL},
    {"Z",VK_CAPITAL},{"Z",0x5A},{"Z",VK_CAPITAL},
    {")",VK_LSHIFT},{")",0x30},{"!",VK_LSHIFT},{"!",0x31},{"@",VK_LSHIFT},{"@",0x32},
    {"#",VK_LSHIFT},{"#",0x33},{"$",VK_LSHIFT},{"$",0x34},{"%",VK_LSHIFT},{"%",0x35},
    {"^",VK_LSHIFT},{"^",0x36},{"&",VK_LSHIFT},{"&",0x37},
    {"(",VK_LSHIFT},{"(",0x39},{"~",VK_LSHIFT},{"~",VK_OEM_3},{"_",VK_LSHIFT},{"_",VK_OEM_MINUS},
    {"{",VK_LSHIFT},{"{",VK_OEM_4},{"}",VK_LSHIFT},{"}",VK_OEM_6},{"|",VK_LSHIFT},{"|",VK_OEM_5},
    {":",VK_LSHIFT},{":",VK_OEM_1},{"\"",VK_LSHIFT},{"\"",VK_OEM_7},{"<",VK_LSHIFT},{"<",VK_OEM_COMMA},
    {">",VK_LSHIFT},{">",VK_OEM_PERIOD},{"?",VK_LSHIFT},{"?",VK_OEM_2}};

    public:
        void typewriterchar(string str,int pos_x,int pos_y,int rest);
        ~typewriter(void){}

};

void typewriter:: typewriterchar(string str,int pos_x = 0,int pos_y = 0,int rest = 10){
    for(int i = 0; i<str.length();i++){
        auto key = string(1,str[i]);
        auto data = keydata.find(key);
        for(int j = 0;j<keydata.count(key);j++){
            typedata.push_back(data->second);
            typedata2.push_back(keydata.count(key));
            data++;
        }
    }
    
    SetCursorPos(pos_x,pos_y);
    Sleep(rest);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    Sleep(rest);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

    for(int i = 0; i< typedata.size();i++){
        if(typedata2[i] == 2 && typedata[i] != VK_LSHIFT){
            keybd_event(VK_LSHIFT,0,KEYEVENTF_EXTENDEDKEY|0,0);
            Sleep(rest/3);
            keybd_event(typedata[i],0,KEYEVENTF_EXTENDEDKEY|0,0);
            Sleep(rest/3);
            keybd_event(typedata[i],0,KEYEVENTF_EXTENDEDKEY |KEYEVENTF_KEYUP,0);
            Sleep(rest/3);
            keybd_event(VK_LSHIFT,0,KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);
            Sleep(rest/3);
        }

        else if (typedata2[i] == 3){
            keybd_event(typedata[i],0,KEYEVENTF_EXTENDEDKEY|0,0);
            Sleep(rest/4);
            keybd_event(typedata[i],0,KEYEVENTF_EXTENDEDKEY |KEYEVENTF_KEYUP,0);
            Sleep(rest/4);
        }

        else{
            Sleep(rest);
            keybd_event(typedata[i],0,KEYEVENTF_EXTENDEDKEY|0,0);
            Sleep(rest);
            keybd_event(typedata[i],0,KEYEVENTF_EXTENDEDKEY |KEYEVENTF_KEYUP,0);
            Sleep(rest);
        }
    }
}

int main(){
    typewriter ty;
    ty.typewriterchar("How Are You?",400,400,50);

    return 0;
}
