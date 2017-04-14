//Welcome to VSP Gadgets
#include<iostream>
#include<conio.h>
#include<math.h>
#include<fstream>
#include<string>
#include <windows.h>
#include<cctype>
#include<cmath>

using namespace std;
const int MAX = 100;
static int m=0;
ofstream fp("formindex.html");
ifstream ft("file.txt");
ofstream fp1("aboutindex.html");
ifstream ft1("file1.txt");


char buffer[MAX];
void calci();
class calc;
static int number=1;
class mynotes
{
private:
    char title[100];
    char note[300];
    char date[100];
public:
    void getnote()
    {
        cout << "Enter Date for Your Note(default Format dd/mm/yyyy) \n";cin >> date;
        cout << "\n Enter title For Your Note :\n " ; cin >> title;
        cout << "\n Enter Your Note:\n " ; cin >> note;

    }
    void showall()
    {
        cout << "\nDate Of Note : " << date;
        cout << "\nTitle Of Note : " << title;
        cout << "\nYour Note is :\n" << note;

    }
    void shownote()
    {
        cout << "\nTitle Of Note : " << title;


    }
    void diskIn(int);
    void diskOut();
    static int diskCount();

};

void mynotes::diskIn(int pn)
{
    ifstream infile;
    infile.open("Notes.dat",ios::binary);
    infile.seekg(pn*sizeof(mynotes));
    infile.read((char *)this,sizeof(*this));



}

void mynotes::diskOut()
{
    ofstream outfile;
    outfile.open("Notes.dat",ios::app | ios::binary);
    outfile.write((char *)this,sizeof(*this));

}
int mynotes::diskCount()
{
ifstream infile;
infile.open("Notes.dat",ios::binary);
infile.seekg(0,ios::end);
return (int)infile.tellg()/sizeof(mynotes);
}
void takenote()
{
    mynotes p;
    char ch;

    do
    {
        cout << "Entering Your Note :: \n";
        p.getnote();

        p.diskOut();

        cout << "\nDo another (y/n)?";
        cin >> ch;
    }while(ch=='y');

}
void viewnotes()
{
    ifstream infile2("Notes.dat");
    if(!infile2.good())
    {
        cout << "Notes File Doesn't Exist so Create a note first \n";
        system("pause");
        return ;
    }


    mynotes p;
    int num;
    int n = mynotes::diskCount();
    cout << "\n There are " << n << " Notes in file\n";

    for(int j=0;j<n;j++)
    {
        cout << "\nNotes Number " << j << "\n";
        p.diskIn(j);
        p.shownote();

    }
    cout << "\nEnter The Number of note You Want to View \n";
    cin >> num;
    if(num > n)
    {
        cout << "\nInvalid Note Number \n";
        system("pause");
        return;
    }
    p.diskIn(num);
    p.showall();
    cout << endl;
    system("pause");
}

void funnote()
{
    int n=0;
    char choice;
    int choice1;
    do{
            system("cls");
            cout << "\n\t1.TakeNotes\n\t2.ViewNotes\n";
            cin >> choice1;
            switch(choice1)
            {
                case 1:takenote();break;
                case 2:viewnotes();break;
                default:return ;break;
            }
            cout << "\nWant To do it again (y/n)? \n" ;




    }while(choice == 'y');
    return ;
}
class calc
{
    float i;
    float j;
    float k;
public:

    void add()
    {
        cout << "\nPerforming Addition \n";
        cout << "\nEnter first number \n";
        cin >> i;
        if(!cin.good())
        {
        cout << "\nInvalid Input  \n Please Enter appropriate Input \n";
        system("pause");
        return;
        }
        cout << "\nEnter second Number\n";
        cin >> j;
        cout << "Addition is :" << i+j;
        cout << endl;
    }
    void sub()
    {
        cout << "\nPerforming Substraction \n";
        cout << "\nEnter first number \n";
        cin >> i;
        if(!cin.good())
        {
        cout << "\nInvalid Input  \n Please Enter appropriate Input \n";
        system("pause");
        return;
        }
        cout << "\nEnter second Number\n";
        cin >> j;
        cout << "Substraction is :" << i-j;
        cout << endl;
    }
    void mult()
    {
        cout << "\nPerforming Multiplication \n";
        cout << "\nEnter first number \n";
        cin >> i;
        if(!cin.good())
        {
        cout << "\nInvalid Input  \n Please Enter appropriate Input \n";
        system("pause");
        return;
        }
        cout << "\nEnter second Number\n";
        cin >> j;
        cout << "Multiplication is :" << i*j;
        cout << endl;

    }
    void div()
    {
        cout << "\nPerforming Division \n";
        cout << "\nEnter first number \n";
        cin >> i;
        if(!cin.good())
        {
        cout << "\nInvalid Input  \n Please Enter appropriate Input \n";
        system("pause");
        return;
        }
        cout << "\nEnter second Number\n";
        cin >> j;
        cout << "Division is :" << i/j;
        cout << endl;
    }
    void sqrt1()
    {
        cout << "Enter a number of which square root is needed\n";
        cin >> k;
        if(!cin.good())
        {
        cout << "\nInvalid Input  \n Please Enter appropriate Input \n";
        system("pause");
        return;
        }
        cout << "Square root is : " << sqrt(k);
        cout << endl;
    }
    void conversions()
    {
        int l;
        const float MTF = 3.2808333F;
        float meter,feet,inches,celcius,fahren;
        float fltfeet;
        float fracfeet;

        cout << "AVAILABLE CONVERSIONS\n\n";
        cout << " 1.Meters To Feet \n 2.Feet To Meters \n 3.Celcius To Farenheit \n 4.Farhenheit To Celcius\n";
        cout << "\n Enter Your Choice ";
        cin >> l;
        switch(l)
        {
            case 1:cout << "\nEnter Meters \n" ; cin >> meter;fltfeet=MTF*meter;feet=int(fltfeet);inches=12*(fltfeet-feet);cout << "Conversion is ";cout << feet << "\'-" << inches << "\"-";break;
            case 2:cout << "\nEnter Feet \n";cin >> feet;cout << "\nEnter inches\n";cin >> inches;fracfeet = inches/12;fracfeet += static_cast<float>(feet);cout << "Conversion is " << fracfeet/MTF;break;
            case 3:cout << "\nEnter temp in celcius\n";cin >> celcius;fahren=celcius*(9/5)+32;cout << "The temp in Farhenheit is " << fahren << "\n";break;
            case 4:cout << "\nEnter temp in fahren\n";cin >> fahren;celcius=fahren*(5/9)-32;cout << "The temp in Celcius is " << celcius << "\n";break;
            default:cout << "\nInvalid Choice \n";system("pause");return;

        }

    }
    void advanced()
    {
        int choice;
        int choice2;
        int choice3;
        int choice4;
        int a,b;
        double a1,b1;
        int result;
        double result1;
        do
 {
 cout<<"\t 1 : Trigonometric Functions \n";
 cout<<"\t 2 : Logarithmic Functions \n";
 cout<<"\t 3 : Power Functions \n";
 cout<<"\t 4:Exit Advanced Functions\n";
 cin >> choice;


 switch(choice)

 {

 case 1:
         {
          cout<<"\n\n";
    cout<<"\t1 : Sin function \n";
          cout<<"\t2 : Cos function \n";
          cout<<"\t3 : Tan function \n";
    cin >> choice2;
    switch(choice2)
    {
    case 1:
     {
     cout<<"\n\n Enter a number...";
     cin>>a1;

     result1=(sin(a1));
     cout<<"\n\nResult = "<<result1<<endl;
     system("pause");
                 break;
     }
    case 2:
     {
    cout<<"\n\n Enter a number...";
     cin>>a1;
                                 result1=(cos(a1));
      cout<<"\n\nResult = "<<result1<<endl;
      system("pause");
      break;
     }
    case 3:
     {
    cout<<"\n\n Enter a number...";
     cin>>a1;
                                 result1=(tan(a1));
      cout<<"\n\nResult = "<<result1<<endl;
      system("pause");
      break;

     }

   }// inner switch
    break;
         }//inner case 2 trignomatic
    case 2:
         {
           cout<<"\n\n";
    cout<<"\t1 : Natural log\n";
    cout<<"\t2 : log with base 10 \n";
    cin >> choice3;
    switch(choice3)
    {
    case 1:
     {
    cout<<"\n\n Enter a number...";
     cin>>a1;
                                 result1=log(a1);
    cout<<"\n\n Result = "<<result1<<endl;
    system("pause");
    break;
   }
    case 2:
     {
     cout<<"\n\n Enter a number...";
     cin>>a1;
            result1= log10(a1);
     cout<<"\n\n Result = "<<result1<<endl;
     system("pause");
     break;
     }
           }// end of switch
           break;
         }// end of case 3 logrithmic
    case 3:
         {
             system("cls");
    cout<<"1) Press 1 for Power \n";
    cout<<"2) Press 2 for Square root \n";
    cout<<"Enter your choice....";
    cin >> choice4;
    switch(choice4)
    {
    case 1:
     {
      cout<<"\n\nEnter a number...";
      cin>>a1;
      cout<<"Enter power...";
      cin>>b1;
      result1=pow(a1,b1);
      cout<<"\n\nResult = "<<result1<<endl;
      system("pause");
      break;
     }
    case 2:
     {
      cout<<"\n\nEnter a number...";
      cin>>a;
      result1=sqrt(a);
      cout<<"\n\nResult = "<<result1<<endl;
      system("pause");
      break;





     }



    }// end of switch

           break;
         }// end of case power function
          case 4:return ;break;

  }// outer switch
}while(choice != 4);


    }
};

void calci()
{


    calc *d;
    int choice;
    char ans;
        do
        {
             system("cls");
             cout << "SCIENTIFIC CALCULATOR\n";
           cout << "Available Functions are \n";
           cout << " 1.Additon \n 2.Substraction \n 3.Multiplication \n 4.Division \n 5.Advanced Functions\n 6.Conversions \n 7.Exit\n\n";
           cout << "Enter your choice\n";
           cin >> choice;
           if(!cin.good())
            {
              cout << "\nInvalid Choice  \n Please Enter appropriate choice \n";
              system("pause");
              break;
            }
           switch(choice)
           {
               case 1:d->add();break;
               case 2:d->sub();break;
               case 3:d->mult();break;
               case 4:d->div();break;
               case 5:d->advanced() ;break;
               case 6:d->conversions();break;
               case 7:return;break;
           }
           cout << "Want to do another calculation(y/n)\n";
           cin >> ans;
        }while(ans == 'y');
}

void clock()
{
      int a = 0;
    int h;
    int m;
    int s;

    mistake:

    cout << "What is the current hour?\n";
    cin >> h;

    cout << "\nWhat is the current minute?\n";
    cin >> m;

    cout << "\nWhat is the current second?\n";
    cin >> s;

    if (h > 24 || m > 60 || s > 60)
    {
          cout << "\nPlease try again!\n\n";
          goto mistake;
    }
    char ch;

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";

    while (!kbhit())
    {
        if(cin.get()=='n')
            break;
        if(!cin.good())
            return;
          cout << h << ":" << m << ":" << s << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
          Sleep(1000);
          s++;
          if (s > 59)
          {
                s = 0;
                m++;

                if (m > 59)
                {
                      m = 0;
                      h++;

                      if (h > 24)
                      {
                            h = 0;
                      }
                }
          }
    }
}
class dynamicwebpage
{
    int s;
public:
   void formwebpages()
 {

    int num;
    int n;
    char c;
    char ch;
    char c2[100];
    char c3[100];
    char c4[100];
    char c5[100];
    char c6[100];
    char option[100];
    char *s="<html>\n<head><title>";
    char *s2 = "</title>\n</head>\n";
    char *p="</body>\n</html>";
    char *p2="<body align=\"center\" opacity=0.8 bgcolor=\"";
    char *p3="\" background=\"";
    char *p4="\"";
    char *p5="style=\"height:720px;width:1380px;border: 10px solid grey;position:relative;float:center;text-align:center;padding:10px;appearance:button;display:inline-block;perspective:250px;border: 3px solid green;\">";
    char *p6="<h1 align=\"center\">";
    char *p7="</h1>";
    char *p8="Submit:<input type=\"submit\" value=\"SUBMIT\" style=\"padding:10px;font-size:16px;background:linear-gradient(#ffbc00 5%,#ffdd7f 100%);border:1px solid #e5a900;color:#4E4D4B;font-weight:700;cursor:pointer;width:20%;border-radius:5px;padding:10px 0;outline:none;\">   &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;              Reset:<input type=\"reset\" value=\"RESET\" style=\"padding:10px;font-size:16px;background:linear-gradient(#ffbc00 5%,#ffdd7f 100%);border:1px solid #e5a900;color:#4E4D4B;font-weight:700;cursor:pointer;width:20%;border-radius:5px;padding:10px 0;outline:none;\"></form></center>\"";
    char *p9="<pre style=\"color:black;\">";
    char *p10="<select name=\"\" style=\"margin:10px 10px 0;background:linear-gradient(#ffdd7f 5%,#ffbc00 100%)\">";
    char *p11="<option>";
    char *p12="</option>";
    char *p13="</select><br><br></pre>";



    if(fp==NULL)
    {
        printf("Error");
        system("pause");
        exit(1);
    }

    fp << s;
    cout << "\nEnter title for your webpage\n";
    cin >> c2;
    fp << c2;
    fp << s2;
    fp << p2;
    cout << "Enter Color For Background \n";
    cin >> c3;
    fp<<c3;
    fp << p3;
    cout << "Enter Image path If you Want image on background\n";
    cin >> c4;
    fp << c4;
    fp << p4;
    fp << p5;
    fp << p6;
    cout << "Enter A heading For Your Form\n";
    cin >> c5;
    fp << c5;
    fp << p7;
    do
    {
        ft.get(c);
        fp << c;

    }while(!ft.eof());
    cout << "Do You Want to create options in the page (y/n)";
    cin >> ch;
    if(ch == 'y')
    {
        fp << p9;
        cout << "Enter a name for the options \n";
        cin >> c6;
        fp << c6;
        fp << p10;
        cout << "How Many Options You Want in form \n";
        cin >> n;
        for(int i=0;i<n;i++)
        {
            fp << p11;
            cout << "Enter your option no " << i << endl;
            cin >> option;
            fp << option;
            fp << p12;

        }
        fp << p13;
        fp << p8;
        cout << "\nForm Has Been Created as Formindex.html \n";

    }
    else
    {
        fp << p8;
        fp << p;

    cout << "\nForm Has Been Created as Formindex.html \n";
    }

   return;
 }
 void aboutwebpages()
 {
    int num;
    char c;
    char c2[20];
    char *s="<html>\n<head><title>";
    char *s2 = "</title>\n</head>\n";
    char *s3 = "<body>\n<p>";
    char *p="</body>\n</html>";


    if(fp1==NULL)
    {
        printf("Error");
        system("pause");
        exit(1);
    }

    fp1 << s;
    cout << "\nEnter title for your webpage\n";
    cin >> c2;
    fp1 << c2;
    fp1 << s2;
    fp1 << s3;
    cout << "\nEnter Heading for your Webpage \n";
    cin  >> c2;
    fp1 << c2;




    do
    {
        ft1.get(c);
        fp1 << c;

    }while(!ft1.eof());
    fp1 << p;

    cout << "\nAbout Webpage Has Been Created \n";

   return;
 }
};
void Dwebpage()
{


    dynamicwebpage *d;
    int choice;
    char ans;
        do
        {
             system("cls");
           cout << "Available Webpage Types are \n";
           cout << "1.SimpleForm \n 2.About Webpage \n 3.Multiplication \n 4.Division \n 5.Exit\n\n";
           cout << "Enter your choice\n";
           cin >> choice;
           if(!cin.good())
            {
              cout << "\nInvalid Choice  \n Please Enter appropriate choice \n";
              system("pause");
              break;
            }
           switch(choice)
           {
               case 1:d->formwebpages();break;
               case 2:d->aboutwebpages();break;
               case 5:return ;break;
           }
           cout << "Want to do another Dynamic Webpage Creation(y/n)\n";
           cin >> ans;
        }while(ans == 'y');
}






int main()
{
    int choice;
    while(true)
    {
    system("cls");
    cout << "\n\nWELCOME TO WEIRD GADGETS\n\n";
    cout << "1.SCIENTIFIC CALCULATOR\n_______________________________________\n2.NotesManager\n_______________________________________\n3.ClockAndTimer\n_______________________________________\n4.DynamicWebpageCreator\n_______________________________________\n5.Exit\n\n";
    cout << "\nWhich Gadget Would You Like to Use";
    cin >> choice;
    if(!cin.good())
    {
        cout << "\nInvalid Choice  \n Please Enter appropriate choice \n";
        system("pause");
        break;
    }
    switch(choice)
    {
        case 1:cout << "Welcome to the calculator\n";calci();break;
        case 2:cout << "Welcome to the NotesManager\n";funnote();break;
        case 3:cout << "Welcome to the Clock and Timer\n";clock();break;
        case 4 :cout << "Welcome to the DynamicWebpageCreator\n";Dwebpage();break;
        case 5: exit(0);break;
    }

    }


    return 0;

}




