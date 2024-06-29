
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>

using namespace std;

struct Newuser
{
    string username;
    string password;
}newuser;
struct loginpage
{
    string logusername;
    string logpassword;
}newlogin;
struct donorsInfo
{
    string fname;
    string lname;
    string address;
    string phone;
    string account;
    string money;
};
struct donateditems
{
    string item;
    string n;
};
struct volunteersInfo
{
    string fname;
    string lname;
    string age;
    string comfort;
    string experience;
    string phone;
};
struct needersInfo
{
    string fname;
    string lname;
    string phone;
    string reason;
};

void registrar();
void login();
void dashBoard();
void donate();
void volunteer();
void applyForNeed();
void listDonors();
void listNeeders();
void listVolunteers();
void donateKind();
void donateMoney();
void listInventory();

int main()
{
    int choice;
    
    cout<<"***********************************************************************************************\n";
    cout<<"***********************************************************************************************\n";
    cout<<"***********************************************************************************************\n\n";
    cout<<"\t\t\t\t Welcome To Donate_With_Ease \n\n";
    
    cout<<"************************************************************************************************\n";
    cout<<"************************************************************************************************\n";
    cout<<"************************************************************************************************\n\n";
    cout<<"********************************************    MENU     *************************************\n\n";


    cout<<"\n 1.Registar\n";
    cout<<" 2.Login\n";
    cout<<" 3.Exit\n";
    cout<<"\n Enter 1.Register first if you are a new user.\n";
    cout<<" Enter 2.login if you have already registered.\n";
    cout<<" Enter 3.If you want to exist.\n";
    cout<<"\nPlease Enter Your choice: \n";
    cin>>choice;
    cout<<endl;
    switch (choice)
    {
        case 1:
            registrar();
            break;
        case 2:
            login();
            break;
        case 3:
            cout<<"Thanks For Using Our Program. This Program Was Created For Our Programming Project ";
            break;
        default:
            system("cls");
            cout<<"You have made a mistake, Try Again..\n";
            main();
    }
    return 0;
}
void registrar()
{
    Newuser newuser;
    system("cls");
    cout<<"Enter new username: ";
    cin>>newuser.username;
    cout<<"Enter new password: ";
    cin>>newuser.password;
    ofstream reg ("credentials.txt",ios::app);
    if(reg.is_open()){
    reg<<newuser.username<<' '<<newuser.password<<endl;
    }
    reg.close();
    system("cls");
    cout<<"\nYou have successfully registered to our database. Please use your credentials(username and password) to login.\n";
    main();
}

void login()
{ 
    loginpage newlogin;
    int checker;
    system("cls");
    string u,p;
    cout<<"Please Enter the credentials you just created to login: "<<endl;
    cout<<"USERNAME: ";
    cin>>newlogin.logusername;
    cout<<"PASSWORD: ";
    cin>>newlogin.logpassword;

    ifstream fin ("credentials.txt");
    while(fin>>u>>p)
    {
        if(u==newlogin.logusername && p==newlogin.logpassword)
        {
            checker=1;
            system("cls");
        }
    }
    fin.close();
    if(checker==1)
    {
        cout<<"\nHello "<<newlogin.logusername<<endl;
        cout<<"LOGIN SUCCESSFUL\n";
        cout<<"Thank you for joining our movement of reaching out to those in need."<<endl;
        cin.get();
        cin.get();
        dashBoard();
    }
    else 
    {
        cout<<"Login Error.\n";
        cout<<"Please check your password and username and try again.\n";
        main();
    }
}

void dashBoard()
{
    int choice;
    cout<<"\n1.To donate."<<endl;
    cout<<"\n2.To register as a volunteer."<<endl;
    cout<<"\n3.To Apply for help(for those in need)."<<endl;
    cout<<"\n4.To list our donators list."<<endl;
    cout<<"\n5.To get info list of those waiting to recieve aid(for donaters who wish to donate directly)."<<endl;
    cout<<"\n6.To list our whole inventory of items."<<endl;
    cout<<"\n7.To list our volunteers list."<<endl;
    cout<<"\n8.EXIT."<<endl;
    
    cout<<"\nEnter your choice: ";
    cin>>choice;
    system("cls");
    switch(choice)
    {
        case 1:
            donate();
            break;
        case 2:
            volunteer();
            break;
        case 3:
            applyForNeed();
            break;
        case 4:
            listDonors();
            break;
        case 5:
            listNeeders();
            break;
        case 6:
            listInventory();
            break;
        case 7:
            listVolunteers();
            break;
        case 8:
            break;
        default:
            cout<<"Invalid Input. Please try again.\n";
            dashBoard();
    }
}

void donate()
{
    int choice;
    cout<<"What is the type of your donation?"<<endl;
    cout<<"\n1.In Kind."<<endl;
    cout<<"2.In Money."<<endl;
    cout<<"\nEnter Your Choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            donateKind();
            break;
        case 2:
            donateMoney();
            break;
        default:
            cout<<"You entered invalid input. Please try again.";
            donate();
    }
}

void donateKind()
{
    donorsInfo donorInfo_1;
    cout<<"Please enter your first name: ";
    cin>>donorInfo_1.fname;
    cout<<"Please enter your last name: ";
    cin>>donorInfo_1.lname;
    cout<<"\nPlease enter your  phone number: ";
    cin>>donorInfo_1.phone;

     int no;
    cout<<"\nHow many kinds of items would you like to donate?(Tshirt,trouser each as a kind in NUMBERS): ";
    cin>>no;
    donateditems ditems[no];
    for(int i=0;i<no;i++)
    {
        cout<<"\nEnter kind of item "<<i+1<<" (shoe,bag,pencil etc..): ";
        cin>>ditems[i].item;
        cout<<"\nHow many "<<ditems[i].item<<"s? ";
        cin>>ditems[i].n;
    }
    cout<<"\nYou entered the following items"<<endl;
    cout<<"Item\t\tNumber"<<endl;
    for(int i=0;i<no;i++)
    {
        cout<<ditems[i].item;
        cout<<"\t\t";
        cout<<ditems[i].n;
        cout<<endl;
    }
    ofstream itemlist("inventory.txt",ios::app);
    if(itemlist.is_open())
    {
        for(int i=0;i<no;i++)
        {

            itemlist<<ditems[i].item;
            itemlist<<"\t\t";
            itemlist<<ditems[i].n;
            itemlist<<endl;
        }
        itemlist.close();
    }
    int m;
    cout<<"\nPlease let us know how you wish to send those items to us: "<<endl;
    cout<<"Note that we cover fees of delivery if more than 10 items are donated."<<endl;
    cout<<"\n1.I will bring it myself."<<endl;
    cout<<"2.Request delivery."<<endl;
    cout<<"\nEnter your choice: ";
    cin>>m;
    switch(m)
    {
        case 1:
            cout<<"You can bring the items to our office"<<endl;
            cout<<"\nLocation:SHIROMEDA, "<<endl;
            cout<<"Or use our number:011";
            cout<<endl;
            break;
        case 2:
            cout<<"Please enter your address: ";
            cin>>donorInfo_1.address;
            cout<<"\nWe will be sending a cab to fetch your items to the entered address.";
            cout<<endl;
            break;
        default:
            cout<<"You entered an invalid value. Please try again.";
            break;
    }
     ofstream myfile12("completeInfo_OfKindDonors.txt",ios::app);
    if(myfile12.is_open())
    {
        myfile12<<endl;
        myfile12<<donorInfo_1.fname<<"  ";
        myfile12<<donorInfo_1.lname<<"  ";
        myfile12<<donorInfo_1.phone<<"  ";
        myfile12<<donorInfo_1.address<<"  ";
        myfile12<<endl;
        myfile12.close();
    }

    ofstream myfile("donorsList.txt",ios::app);
    if(myfile.is_open())
    {
        myfile<<endl;
        myfile<<donorInfo_1.fname<<'\t'<<donorInfo_1.lname<<endl;
        myfile.close();
    }
    cout<<endl;
    cout<<"Press enter to wipe screen and return to dashboard....";
    cin.get();
    cin.get();
    system("cls");
    dashBoard();
}

void donateMoney()
{
    donorsInfo donatebirr;
    cout<<"You are on our donation with money page."<<endl;
    cout<<"\nPlease enter your first name: ";
    cin>>donatebirr.fname;
    cout<<"\nPlease enter your last name: ";
    cin>>donatebirr.lname;
    cout<<"Please enter your account number: ";
    cin>>donatebirr.account;
    cout<<"Please enter the amount of money you would like to deposit: ";
    cin>>donatebirr.money;

    cout<<"\n\nThe way we recieve donation in money is by sending"<<endl;
    cout<<"you our agency account number and once you deposit to that"<<endl;
    cout<<"account we will update our database and accordingly share"<<endl;
    cout<<"the allocated budget to all those in need.\n\n";
    cout<<"You can deposit to any of the below account numbers: "<<endl;
    cout<<"\nAccount Owner: DonateWithEase Agency"<<endl;
    cout<<"CBE Account: 1000"<<endl;
    cout<<"Abyssinia:1920 "<<endl;
    cout<<"Zemen Bank:3894"<<endl;
    cout<<"Awash Bank:2894 "<<endl;


    cout<<"\n\nYou entered the following information. "<<endl;
    cout<<"Name\t\tAccount number\t\tAmount"<<endl;
    cout<<donatebirr.fname<<' '<<donatebirr.fname;
    cout<<"\t\t";
    cout<<donatebirr.account;
    cout<<"\t\t";
    cout<<donatebirr.money;
    cout<<endl;
    cout<<"\n\n-------THANK YOU FOR YOUR KIND DEEDS-------\n";
    cout<<"--------WE WILL MAKE SURE TO RECIPROCATE YOUR DEEDS TO THOSE IN NEED------\n";

    ofstream myfile12("completeInfo_MoneyDonors.txt",ios::app);
    if (myfile12.is_open())
    {
        myfile12<<donatebirr.fname;
        myfile12<<"\t\t";
        myfile12<<donatebirr.account;
        myfile12<<"\t\t";
        myfile12<<donatebirr.money;
        myfile12<<endl;
        myfile12.close();
    }

    ofstream myfile2("donorsList.txt",ios::app);
    if(myfile2.is_open())
    {
        myfile2<<endl;
        myfile2<<donatebirr.fname<<' '<<donatebirr.lname<<endl;
        myfile2.close();
    }

    cout<<endl;
    cout<<"Press enter to wipe screen and return to dashboard....";
    cin.get();
    cin.get();
    system("cls");
    dashBoard();

}

void volunteer()
{
    volunteersInfo volunteers;
    int n,m;
    cout<<"This is the option to register to be a volunteer."<<endl;
    cout<<"\nPlease enter your first name: ";
    cin>>volunteers.fname;
     cout<<"\nPlease enter your last name: ";
    cin>>volunteers.lname;
    cout<<"\nPlease enter your age: ";
    cin>>volunteers.age;
    cout<<"\nPlease enter your phone number: ";
    cin>>volunteers.phone;
    cout<<"\nWhat is your comfort of work range?"<<endl;
    cout<<"1.Any(Near home or away)"<<endl;
    cout<<"2.Only nearby."<<endl;
    cout<<"\nYour Choice: "<<endl;
    cin>>m;
    switch(m)
    {
        case 1:
            volunteers.comfort="Any";
            break;
        case 2:
            volunteers.comfort="Nearby";
    }
    cout<<"Have you volunteered for any charity work before? ";
    cout<<"\n1.No\n";
    cout<<"2.Yes\n";
    cin>>n;
    switch(n)
    {
        case 1:
            volunteers.experience="Inexperienced";
            break;
        case 2:
            volunteers.experience="Experienced";
            break;
    }

    cout<<endl;
    cout<<"You Entered the following data. "<<endl;
    cout<<"Full Name\t\tAge\t\tComfort\t\t Experience"<<endl;
    cout<<volunteers.fname<<' '<<volunteers.lname<<"\t\t";
    cout<<volunteers.age<<"\t\t";
    cout<<volunteers.comfort<<"\t\t";
    cout<<volunteers.experience<<endl;

    cout<<endl;
    cout<<"-----------THANK YOU----------------"<<endl;
    cout<<"We will add your application to our volunteers list and contact you with your specfied phone number.";
    cout<<endl;

    ofstream myfile("volunteersList.txt",ios::app);
    if(myfile.is_open())
    {
    myfile<<endl;
    myfile<<volunteers.fname<<"\t\t";
    myfile<<volunteers.lname<<"\t\t";
    myfile<<volunteers.age<<"\t\t";
    myfile<<volunteers.comfort<<"\t\t";
    myfile<<volunteers.experience<<endl;
    myfile.close();
    }

    cout<<endl;
    cout<<"Press enter to wipe screen and return to dashboard....";
    cin.get();
    cin.get();
    system("cls");
    dashBoard();
}

void applyForNeed()
{
    needersInfo applys;
    int choice;
    cout<<"\nThis is our page dedicated for those who would like to benefit from our organization."<<endl;
    cout<<"\nPlease enter your first name: ";
    cin>>applys.fname;
    cout<<"\nPlease enter your last name: ";
    cin>>applys.lname;
    cout<<"\nPlease enter your phone number: ";
    cin>>applys.phone;
    cout<<"\nPlease select what exactly you need aid in from the below options: "<<endl;
    cout<<"\n1.Medical fees."<<endl;
    cout<<"\n2.Displaced Due To various circumstances."<<endl;
    cout<<"\n3.Housing(living in the streets)."<<endl;
    cout<<"\n4.Student(Educational expenses)."<<endl;
    cout<<"\n5.Disabilty."<<endl;
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            applys.reason="Medical Fees";
            break;
        case 2:
            applys.reason="Displaced Due To Various Circumstances";
            break;
        case 3:
            applys.reason="Housing(living in the streets)";
            break;
        case 4:
            applys.reason="Student(Educational Expenses)";
            break;
        case 5:
            applys.reason="Disability";
            break;
        default:
            cout<<"Invalid Input.Please try again.";
            applyForNeed();
    }

    cout<<endl;
    cout<<"You entered the following data: "<<endl;
    cout<<"Name \t\t Phone Number\t\tReason"<<endl;
    cout<<applys.fname<<' '<<applys.lname<<"\t\t";
    cout<<applys.phone<<"\t\t";
    cout<<applys.reason<<endl;

    ofstream myfile ("needersList.txt",ios::app);
    if(myfile.is_open())
    {
    cout<<endl;
    myfile<<applys.fname<<"\t";
    myfile<<applys.lname<<"\t";
    myfile<<applys.phone<<"\t\t";
    myfile<<applys.reason<<endl;
    myfile.close();
    }

    cout<<endl;
    cout<<"We need you to submit supporting documents for your claim."<<endl;
    cout<<"You may use our email DonateWithEase@gmail.com to submit the documents."<<endl;
    cout<<"Or you may come in person to our office located in SHIROMEDA"<<endl;
    cout<<endl; 

    cout<<"We will get back to you after revieiwing your documents."<<endl;
    cout<<"\n-------THANK YOU FOR YOUR PATIENCE------------------"<<endl;
    cout<<"---------------HELP IS ON THE WAY-------------------"<<endl;

    cout<<endl;
    cout<<"Press enter to wipe screen and return to dashboard....";
    cin.get();
    cin.get();
    system("cls");
    dashBoard();
}

void listDonors()
{
    cout<<"-------Below is the list of donors who had been helping our organization ";
    cout<<"reach thousands in need of aid.---------------------"<<endl;
    cout<<"\nWe would again like to Thank all these people."<<endl;
    cout<<"-------------Your help is much appreciated.------------------- "<<endl;
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"Name"<<endl;
    ifstream myfile("donorsList.txt");
    string line;
    while(getline(myfile,line))
    {
        cout<<line<<endl;
    }
    myfile.close();
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Press enter to wipe screen and return to dashboard....";
    cin.get();
    cin.get();
    system("cls");
    dashBoard();
}   

void listNeeders()
{
    cout<<"Below listed are those people registered to recieve aid."<<endl;
    cout<<"\nWe have attached their phone numbers in case you want to contact any of them."<<endl;
    cout<<"\nOur list also includes the issue they are facing in the reasons section."<<endl;
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    ifstream myfile("needersList.txt");
    string line;
    while(getline(myfile,line))
    {
        cout<<line<<endl;
    }
    myfile.close();
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"But note that some people listed here are those which we have not yet reviewed supporting documents";
    cout<<" they submitted confirming their stated reasons."<<endl;
    cout<<"\nSo make sure to contact our office before donating directly to confirm the status of the pending users."<<endl;
    cout<<"\n--------------THANK YOU----------------------------"<<endl;
    cout<<endl;

    cout<<endl;
    cout<<"Press enter to wipe screen and return to dashboard....";
    cin.get();
    cin.get();
    system("cls");
    dashBoard();
}

void listInventory()
{
    cout<<"Below is the list of items currently in our store. Donated by fellow donaters all around."<<endl;
    cout<<"\nThe items along with their numbers are listed. "<<endl;
    cout<<"\nIt is by your continued efforts that we can continue to make the inventory go bigger so";
    cout<<" make sure to donate if you got any items that can be of help";
    cout<<"\n-----------------------------------------------------------------------\n\n";
    cout<<"Items\t\tnumbers"<<"\n";
    ifstream myfile("inventory.txt");
    if(myfile.is_open())
    {
        string line;
        while(getline(myfile,line))
        {
            cout<<line<<endl;
        }
        myfile.close();
    }

    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Press enter to wipe screen and return to dashboard....";
    cout<<endl;
    cin.get();
    cin.get();
    system("cls");
    dashBoard();
}

void listVolunteers()
{
    cout<<"Below is a list of people who have volunteered to come in person and help those in need."<<endl;
    cout<<"The list also has information about the people."<<endl;
    cout<<"The information includes the age,phone number,whether they are willing to travel away from home for the volunteer work or not"<<endl;
    cout<<"And also whether they have participated in any volunteer work prior or not."<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"first Name\tlast name\tAge\t\tComfort\t\t Experience"<<endl;
    ifstream myfile("volunteersList.txt");
    string line;
    while(getline(myfile,line))
    {
        cout<<line<<endl;
    }
    myfile.close();
    cout<<"----------------------------------------------------------------------------------"<<endl;

    cout<<endl;
    cout<<"Press enter to wipe screen and return to dashboard....";
    cin.get();
    cin.get();
    system("cls");
    dashBoard();
}