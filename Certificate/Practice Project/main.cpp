#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <dirent.h>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <time.h>

using namespace std; // ���������� ����������� ������������ ����


void GetFileAgeDays(const char* file, string path)
{
        double eleven_month = 60 * 60 * 24 * 30.4 * 11;
        //double twelve_month = 60 * 60 * 24 * 365;
        double file_age = 0;
        double twelve_month = 31557600;

        time_t CurrentTime, FileTime;

        struct _stat st;
        _stat(file, &st);
        char mod[100];

        FileTime = st.st_mtime;

        time( &CurrentTime );
        double DiffSeconds = difftime( CurrentTime, FileTime );
        //return DiffSeconds / 60.0 / 60.0 / 24.0;
        file_age = DiffSeconds / 60 / 60 / 24 / 30.4;
        std::ofstream out("C:\\Certificate\\Practice Project\\all_user_certificates.txt", std::ios::app);
        std::ofstream out1("C:\\Certificate\\Practice Project\\old_certificates.txt", std::ios::app);     // ����� ��� ������
        std::ofstream out2("C:\\Certificate\\Practice Project\\active_certificates.txt", std::ios::app);
        std::ofstream out3("C:\\Certificate\\Practice Project\\ancient_user_certificates.txt", std::ios::app);

   if ((out.is_open()) && (out1.is_open()) && (out2.is_open()) && (out3.is_open()))
    {
        out << "Employee's name: " << path << std::endl;
        out << "File age: " << file_age << " month" << std::endl;

        if ((DiffSeconds > eleven_month) && (DiffSeconds < twelve_month)) {
            out << "���������� ���������� " <<  std::endl;
            out1 << "Employee's name: " << path << std::endl;
            out1 << "File age: " << file_age << " month" << std::endl;
            out1 << "���������� ���������� " <<  std::endl;
            out1 <<  std::endl;
        } else if ((DiffSeconds < eleven_month)){
            out << "���������� ��������� " <<  std::endl;
            out2 << "Employee's name: " << path << std::endl;
            out2 << "File age: " << file_age << " month" << std::endl;
            out2 << "���������� ��������� " <<  std::endl;
            out2 <<  std::endl;
        }else if ((DiffSeconds > eleven_month)){
            out << "���������� ������� " <<  std::endl;
            out3 << "Employee's name: " << path << std::endl;
            out3 << "File age: " << file_age << " month" << std::endl;
            out3 << "���������� ������� " <<  std::endl;
            out3 <<  std::endl;
        }
        out <<  std::endl;
    }
    out3.close();
    out2.close();
    out1.close();
    out.close();
}


char data_izmemeniya(const char* file, string path)
{
    struct _stat st;
    _stat(file, &st);
    char mod[100];
    ctime_s(mod, 100, &st.st_mtime);

    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);

    cout << "Current Datetime:" << asctime(timeinfo)  << endl;
    st.st_mtime;
    std::ofstream out("C:\\Certificate\\Practice Project\\sorted_user_certificates.txt", std::ios::app);     // ����� ��� ������
    if (out.is_open())
    {
        out << "File directory " << path << std::endl;
        out << "Data izmeneniya " << mod << std::endl;
    }
    out.close();
}


void get_user_logins(char* directory)
{
    DIR *dir;
struct dirent *ent;
if ((dir = opendir (directory)) != NULL) {

   //print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    std::ofstream out("C:\\Certificate\\Practice Project\\user_logins.txt", std::ios::app);     // ����� ��� ������
    if (out.is_open())
    {
        string s1 = ent->d_name;
        if (s1 != "." && s1 != ".."){
        out << ent->d_name << std::endl;
        }
    }
    out.close();
  }
  closedir (dir);
}
}

void get_user_cer_files(char* directory)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (directory)) != NULL) {

   //print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    std::ofstream out("C:\\Certificate\\Practice Project\\user_sertificates.txt", std::ios::app);     // ����� ��� ������
    if (out.is_open())
    {
        string s1 = ent->d_name;
        if (s1.find(".cer") != std::string::npos)
            out << ent->d_name << std::endl;
    }
    out.close();
  }
  closedir (dir);
}
}

void sort_cer_files(){
    ifstream file("C:\\Certificate\\Practice Project\\user_sertificates.txt");//������� ������ ������ istream  �� ����� file
                        // ������� ����������������  ������ fileName,
                       //���������� ������� file.open();
        string str;         //���������� ������ ��� ������
        while(getline(file,str)) //getline(istream & is, string &s,char c='\n'),������ �� ������ is, � ������ s ����
        {                        //�� �������� ������ c (��� ����� ������� �� ����� ������)
                       // ���������� ���� ������ istream, � ������� ����������� ��������� iostate ����a, �������� ����� ����� ����� ������, ���� ��������� ����� �����, ��� ����� ������ ����� ��� ��������� ����
        str += "+"; // ��� ������ ������ �� ������� �������� � �������� ������ � ����� ������ ������
        std::ofstream out("C:\\Certificate\\Practice Project\\user_sertificates.txt", std::ios::app);     // ����� ��� ������
        if (out.is_open())
        {
        }
    out.close();
        }
        file.close(); // ����������� ��������� ���� ��� �� �� ��������� ���
}

int main(int argc, char **argv)
{
    char* dir = "C:\\Certificate\\users\\";

    get_user_logins(dir);                                          // �������� ������ ������� ������������� � ��������


        ifstream file("C:\\Certificate\\Practice Project\\user_logins.txt");//������� ������ ������ istream  �� ����� file
                        // ������� ����������������  ������ fileName,
                       //���������� ������� file.open();ifstream file2("C:\\Certificate\\Practice Project\\user_sertificates.txt");//������� ������ ������ istream  �� ����� file
                        // ������� ����������������  ������ fileName,
                       //���������� ������� file.open();

        string str;         //���������� ������ ��� ������

        while(getline(file,str)) //getline(istream & is, string &s,char c='\n'),������ �� ������ is, � ������ s ����
        {                        //�� �������� ������ c (��� ����� ������� �� ����� ������)
                       // ���������� ���� ������ istream, � ������� ����������� ��������� iostate ����a, �������� ����� ����� ����� ������, ���� ��������� ����� �����, ��� ����� ������ ����� ��� ��������� ����

        string papka = "C:\\Certificate\\users\\";
        string user_name = str;
        string user_login = papka + user_name;
        char* path = strdup(user_login.c_str());
        get_user_cer_files(path);

ifstream file2("C:\\Certificate\\Practice Project\\user_sertificates.txt");//������� ������ ������ istream  �� ����� file
                        // ������� ����������������  ������ fileName,
                       //���������� ������� file.open();

        string str2;         //���������� ������ ��� ������
        while(getline(file2,str2)) //getline(istream & is, string &s,char c='\n'),������ �� ������ is, � ������ s ����
        {                        //�� �������� ������ c (��� ����� ������� �� ����� ������)
                       // ���������� ���� ������ istream, � ������� ����������� ��������� iostate ����a, �������� ����� ����� ����� ������, ���� ��������� ����� �����, ��� ����� ������ ����� ��� ��������� ����

        string user_name_cer = str2;

        if (user_name_cer.find(user_name) != std::string::npos){
        string user_login_cer = user_login + "\\" + user_name_cer;
        cout << user_login_cer << endl;
        char* put = strdup(user_login_cer.c_str());

        //data_izmemeniya(put, user_login_cer);
        GetFileAgeDays(put, user_name);
        }
        }

        file2.close();
        }

        file.close(); // ����������� ��������� ���� ��� �� �� ��������� ���

        //char* file_cer = "C:\\Certificate\\users\\aafanasiev\\aafanasiev.cer";
        //data_izmemeniya(file_cer);

    _getch();
    return 0;
}
