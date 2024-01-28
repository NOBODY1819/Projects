// Registration and login page using C++

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void login(){  // Login function with wrong username and password checking
    int count;
    string usr_email,user_id, password, id,email, pass;
    system("cls");
    cout<<"\nPlease enter the username and password\n\n"<<endl;
    cout<<"Username = ";
    cin>>user_id;
    cout<<"Password = ";
    cin>>password;

    ifstream f1("records.txt");
    count=-1;
    while (!f1.eof())
    {   
        getline(f1,id,'*');
        getline(f1,email,'*');
        getline(f1,pass,'\n');
        if (id==user_id){
            if(password == pass){
                count=1;
                break;
            }else{
                count=0;
                break;
            }
        }
    }
    f1.close();

    if(count==1){
        cout<<"\n\t<-########-> LOGIN SUCCESSFUL <-########->\n";
        cout<<"\n\t\t Account details\n\nE-mail : "<<email<<"\nUsername : "<<user_id<<"\nPassword : "<<pass<<endl;
        
    }else if (count==0)
    {
        cout<<"\n\t!!!! LOGIN ERROR: Wrong Password Try again !!!!\n";

    }else if (count==-1)
    {
        cout<<"\n\t!!!! LOGIN ERROR: Username not found !!!!\n";
    }
    
    return;
}
void sign_up(){   // sign-up function with condition check if email or username already used
    string usr_name,usr_email, usr_pass,email,id,pass;
    int count = 1;
    system("cls");
    cout<<"\n <-$$$$$$$$-> NEW SIGN-UP <-$$$$$$$$->\n";
    cout<<"\nPlease enter the details\n\n"<<endl;
    cout<<"E-mail = ";
    cin>>usr_email;
    cout<<"Username = ";
    cin>>usr_name;
    ifstream file_p("records.txt");
    while (!file_p.eof())
    {
        getline(file_p,id,'*');
        getline(file_p,email,'*');
        getline(file_p,pass,'\n');
        if (usr_name==id){
            count=-1;
            break;
        }else if (usr_email==email)
        {
            count=0;
            break;
        }
        
    }
    file_p.close();
    if (count==1){
        cout<<"Password = ";
        cin>>usr_pass;
        ofstream f1("records.txt", ios::app);
        f1<<usr_name<<'*'<<usr_email<<"*"<<usr_pass<<endl;
        f1.close();
        system("cls");
        cout<<"\n\t<-########-> SIGN-UP SUCCESFUL <-########->\n";
        return;
    }else if (count==-1){
        cout<<"\n\nEmail alredy registered! Try Forgot password.\n";
        return;
    }else if(count==0){
        cout<<"\n\nUsername already used!! Try anothe username.\n";
        return;
    }else{
        cout<<"\nError while registring!!\n";
    }
    return;

}
void forgot_password(){
    char option;
    string usr_id,usr_email,email,id, pass;
    system("cls");
    cout<<"\n\n\t FORGOT PASSWORD MENU\n";
    cout<<"Press 1 to search using userid\nPress 2 to search using Email\nPress anything else to go back\n\nEnter choice : ";
    cin>>option;
    ifstream f2("records.txt");
    int count=0;
    switch (option)
    {
    case '1':
        cout<<"\nEnter the username : ";
        cin>>usr_id;
        while (!f2.eof())
        {   
            getline(f2,id,'*');
            getline(f2,email,'*');
            getline(f2,pass,'\n');
            if(id==usr_id){
                count=1;
                break;
            }
        }
        if (count==1){
            cout<<"\nAccount Found Successfully\nUsername = "<<usr_id<<"\nEmail = "<<email<<"\nPassword = "<<pass<<endl;
        }else{
            cout<<"\n Account Not Found\n";
        }
        break;
    case '2':
        cout<<"\nEnter the E-mail : ";
        cin>>usr_email;
        while (!f2.eof())
        {   
            getline(f2,id,'*');
            getline(f2,email,'*');
            getline(f2,pass,'\n');
            if(email==usr_email){
                count=1;
                break;
            }
        }
        if (count==1){
            cout<<"\nAccount Found Successfully\nUsername = "<<id<<"\nEmail = "<<email<<"\nPassword = "<<pass<<endl;
        }else{
            cout<<"\n Account Not Found\n";
        }
        break;
    default:
        cout<<"\n\t\t!!!! Going Back to Main Menu !!!!\n";
        break;
    }
    
    f2.close();

    return;

}

int main(){
    char choice;
    while (choice!='4'){
    cout<<" <------------> Main Menu <---------->\n\n"<<endl;
    cout<<"\tPress 1 for Login\n\tPress 2 for Sign-up\n\tPress 3 for Forgot Password\n\tPress 4 for Exit\n Enter your choice : ";
    cin>>choice;
    cout<<endl;
    
    switch (choice)
    {
    case '1':
        login();
        break;
    case '2':
        sign_up();
        break;
    case '3':
        forgot_password();
        break;
    case '4':
        cout<<"\n\n\t****** Thank you for using this service *******\n"<<endl;
        break;
    default:
        // system("cls");
        cout<<"Please enter for given choices!!!!"<<endl;
        break;
        }
    }
}
