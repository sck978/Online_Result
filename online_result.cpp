#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>

class stu
{
	long rollno;
	char name[25];
	char school[25];
	float m[5];
	float marks;
	char sub[6][25];
	char grade;

	public:
	void putfulldata();
	void getdata();
	void sel_sub();
	void sort(float[],char [6][25]);
	void tot();
	void gra();
	void modify();

	char* getschool()
	{
		return school;
	}

	char getgrade()
	{
		return grade;
	}

	long getrno()
	{
		return rollno;
	}

}s1[100],stud[100];

	void stu::putfulldata()
	{
		cout<<"\n\n\t\t\tNAME OF THE CANDIDATE : "<<name;
		cout<<"\n\n\t\t\tROLL NO. : "<<rollno;
		cout<<"\n\n\t\t\tSCHOOL OF THE CANDIDATE : "<<school;
		cout<<"\n\n\t\t\tMARKS OBTAINED PER SUBJECT : \n";
		for(int i=0;i<5;i++)
		{
			if(strcmpi(sub[i],"null"))
			cout<<"\n\n\t\t\t"<<sub[i]<<" : "<<m[i];
		}
		cout<<"\n\n\t\t\tPERCENTAGE : "<<marks;
		cout<<"\n\n\t\t\tGRADE : "<<grade;
		cout<<endl;
	}

	void stu::getdata()
	{
		char ch;
		cout<<"\n\n\t\t\tRollno :";
		cin>>rollno;
		cin.get(ch);
		cout<<"\n\n\t\t\tName :";
		gets(name);
		cout<<"\n\n\t\t\tSchool Name (in full) :";
		gets(school);
		sel_sub();
		for(int i=0;i<6;i++)
		{
			if(strcmpi(sub[i],"null"))
			{
				cout<<"\n\n\t\t\tEnter Marks in :"<<sub[i]<<":";
				cin>>m[i];
			}
			else
				m[i]=0;
		}
		gra();
	}

	void stu::sel_sub()
	{
		strcpy(sub[0],"English");
		cout<<"\n\n\t\t\tYou have English compulsory as your first subject.\n";
		for(int i=1;i<5;i++)
		{
			cout<<"\n\n\t\t\tEnter subject "<<(i+1)<<":";
			gets(sub[i]);
		}
		char ch;
		cout<<"\n\n\t\t\tDo you want to take a sixth subject(y/n):";
		cin>>ch;
		if(ch=='y'||ch=='Y')
		{
			cout<<"\n\n\t\t\tEnter subject 6:";
			gets(sub[5]);
		}
		else
			strcpy(sub[5],"null");
	}

	void stu::sort(float ar[],char sb[6][25])
	{
		char s[25];
		for(int i=1;i<5;i++)
		{
			for(int j=i+1;j<6;j++)
			{
				if(ar[i]<ar[j])
				{
					float tm=ar[i];
					ar[i]=ar[j];
					ar[j]=tm;

					strcpy(s,sb[i]);
					strcpy(sb[i],sb[j]);
					strcpy(sb[j],s);
				}
			}
		}
	}

	void stu::tot()
	{
		marks=0;
		for(int i=0;i<5;i++)
			marks+=m[i];
		marks/=5;

	}

	void stu::gra()
	{
		sort(m,sub);
		tot();

		if(m[0]<40)
		{
			grade='F';
			return ;
		}

		if(m[0]<40||m[1]<40||m[2]<40||m[3]<40||m[4]<40)
		{
			grade='F';
			return ;
		}

		if(marks>=75)
			grade='A';
		else if(marks>=60)
			grade='B';
		else if(marks>=50)
			grade='C';
		else if(marks>=40)
			grade='D';
		else
			grade='F';
	}

	void stu::modify()
	{
		putfulldata();
		cout<<"\n\n\t\t\tEnter new details."<<endl;
		char ch,nm[20];
		float mks[5];
		cin.get(ch);
		cout<<"\n\n\t\t\tCorrected Name:";
		gets(nm);
		strcpy(name,nm);

		for(int i=0;i<5;i++)
		{
			cout<<"\n\n\t\t\tCorrected Marks in "<<sub[i]<<": ";
			cin>>mks[i];
		}
		for(i=0;i<5;i++)
		{
			m[i]=mks[i];
		}

		tot();
		gra();
	}

	void add()
	{
		clrscr();
		char pass[8];
		cout<<"\t\t\t\t\twww.results@12.com\n";
		cout<<"\n\n\n\t\t\tEnter password 1:";
		gets(pass);
		if(!strcmpi(pass,"sudhir"))
		{
			cout<<"\n\n\t\t\tEnter password 2:";
			gets(pass);
			if(!strcmpi(pass,"memorial"))
			{
				cout<<"\n\n\t\t\tEnter password 3:";
				gets(pass);
				if(!strcmpi(pass,"institute"))
				{
					cout<<"\n\n\t\t\tALL THE PASSWORDS MATCHED!!\n";
				}
				else
				{
					cout<<"\n\n\t\t\tWRONG PASSWORD!!\n";
					return ;
				}
			}
			else
			{
					cout<<"\n\n\t\t\tWRONG PASSWORD!!\n";
					return ;
			}
		}
		else
		{
			cout<<"\n\n\t\t\tWRONG PASSWORD!!\n";
			return ;
		}

		ofstream fo("report.txt",ios::app);
		char ans='y';
		int i=0;
		while(ans=='y'||ans=='Y')
		{
			s1[i].getdata();
			fo.write((char*)&s1[i],sizeof(s1[i]));
			i++;
			cout<<"\n\n\t\t\tRecord added to file.\n";
			cout<<"\n\n\t\t\tWant to enter more records?(y/n):";
			cin>>ans;
		}

		fo.close();
	}

	void search()
	{
		clrscr();
		long rn;
		int i=0;
		char found='n';
		ifstream fi("report.txt",ios::in);
		cout<<"\t\t\t\t\twww.results@12.com\n";
		cout<<"\n\n\n\t\t\tEnter rollno to be searched for:";
		cin>>rn;
		while(!fi.eof()&&rn!=0)
		{
			fi.read((char*)&s1[i],sizeof(s1[i]));
			if(s1[i].getrno()==rn)
			{
				s1[i].putfulldata();
				found='y';
				break;
			}
			i++;
		}
		if(found=='n')
			cout<<"\n\n\t\t\tRollno not found in file!!"<<endl;

		fi.close();
	}

	void del()
	{
		clrscr();
		char pass[8];
		cout<<"\t\t\t\t\twww.results@12.com\n";
		cout<<"\n\n\n\t\t\tEnter password 1:";
		gets(pass);
		if(!strcmpi(pass,"sudhir"))
		{
			cout<<"\n\n\t\t\tEnter password 2:";
			gets(pass);
			if(!strcmpi(pass,"memorial"))
			{
				cout<<"\n\n\t\t\tEnter password 3:";
				gets(pass);
				if(!strcmpi(pass,"institute"))
				{
					cout<<"\n\n\t\t\tALL THE PASSWORDS MATCHED!!\n";
				}
				else
				{
					cout<<"\n\n\t\t\tWRONG PASSWORD!!\n";
					return ;
				}
			}
			else
			{
					cout<<"\n\n\t\t\tWRONG PASSWORD!!\n";
					return ;
			}
		}
		else
		{
			cout<<"\n\n\t\t\tWRONG PASSWORD!!\n";
			return ;
		}

		ifstream fio("report.txt",ios::in);
		ofstream file("temp.txt",ios::out);
		long rno;int i=0;char found='f';
		cout<<"\n\n\t\tEnter rollno of student whose record is to be deleted\n\n\t\t";
		cin>>rno;
		fio.seekg(0);
		while(!fio.eof()&&rno!=0)
		{
			fio.read((char*)&s1[i],sizeof(s1[i]));
			if(s1[i].getrno()!=rno)
			{
				file.write((char*)&s1[i],sizeof(s1[i]));
			}
			else
			{
				cout<<"\n\n\t\t\tSUCCESFULLY DELETED!!!\n";
				found='t';
				i--;
			}
			i++;
		}
		if(found=='f')
		cout<<"\n\n\t\t\tRecord not found!!\n";

		fio.close();
		file.close();
		remove("report.txt");
		rename("temp.txt","report.txt");
	}

	void mod()
	{
		clrscr();
		char pass[8];
		cout<<"\t\t\t\t\twww.results@12.com\n";
		cout<<"\n\n\n\t\t\tEnter password 1:";
		gets(pass);
		if(!strcmpi(pass,"sudhir"))
		{
			cout<<"\n\n\t\t\tEnter password 2:";
			gets(pass);
			if(!strcmpi(pass,"memorial"))
			{
				cout<<"\n\n\t\t\tEnter password 3:";
				gets(pass);
				if(!strcmpi(pass,"institute"))
				{
					cout<<"\n\n\t\t\tALL THE PASSWORDS MATCHED!!\n";
				}
				else
				{
					cout<<"\n\n\t\t\tWRONG PASSWORD!!\n";
					return ;
				}
			}
			else
			{
					cout<<"\n\n\t\t\tWRONG PASSWORD!!\n";
					return ;
			}
		}
		else
		{
			cout<<"\n\n\t\t\tWRONG PASSWORD!!\n";
			return ;
		}

		fstream fio("report.txt",ios::in|ios::out|ios::binary);
		long rno;int i=0;long pos;char found='f';
		cout<<"\n\n\n\t\tEnter rollno of the student whose record is to be modified\n\n\t\t";
		cin>>rno;
		fio.seekg(0);
		while(!fio.eof()&&rno!=0)
		{
			pos=fio.tellg();
			fio.read((char*)&s1[i],sizeof(s1[i]));
			if(s1[i].getrno()==rno)
			{
				s1[i].modify();
				fio.seekg(pos);
				fio.write((char*)&s1,sizeof(s1));
				found='t';
				cout<<"\n\n\t\t\tSUCCESFULLY MODIFIED!!!\n";
				break;
			}
			i++;
		}
		if(found=='f')
		cout<<"\n\n\t\t\tRecord not found!!\n";

		fio.close();
	}

	void sorting_school()
	{
		clrscr();
		int i=0;
		char sc[25];
		char found='n';
		cout<<"\t\t\t\t\twww.results@12.com\n";
		ifstream fi("report.txt",ios::in);
		cout<<"\n\n\n\t\t\tEnter school name (in full) to be searched for:";
		gets(sc);
		while(!fi.eof())
		{
			fi.read((char*)&s1[i],sizeof(s1[i]));
			if(!strcmpi(s1[i].getschool(),sc))
			{
				s1[i].putfulldata();
				found='y';
			}
			i++;
		}

		if(found=='n')
			cout<<"\n\n\t\t\tResult not found !!"<<endl;

		fi.close();
	}

	void sorting_grade()
	{
		clrscr();
		int i=0;
		char gr;
		char found='n';
		cout<<"\t\t\t\t\twww.results@12.com\n";
		ifstream fi("report.txt",ios::in);
		cout<<"\n\n\n\t\t\tEnter grade to be searched for:";
		cin>>gr;
		while(!fi.eof())
		{
			fi.read((char*)&s1[i],sizeof(s1[i]));
			if(s1[i].getgrade()==toupper(gr)||s1[i].getgrade()==tolower(gr))
			{
				s1[i].putfulldata();
				found='y';
			}
			i++;
		}

		if(found=='n')
			cout<<"\n\n\t\t\tResult not found !!"<<endl;

		fi.close();
	}

	void main()
	{
		int choice=0;
		clrscr();
		cout<<"\t\t\t\t\t\twww.results@12.com\n\n\n\n\n\n\t\t\t\tWELCOME TO THE OFFICIAL SITE";
		for(double i=0.0;i<10000.0;i+=0.0001);
		clrscr();
		cout<<"\n\n\n\n\n\n\t\t\t\tLOADING....";
		for(i=0.0;i<10000.0;i+=0.0001);
		clrscr();
		cout<<"\t\t\t\t\t\twww.results@12.com\n\n\n\n\n\n\tDOUBLE PRESS 'X' TO EXIT\tDOUBLE PRESS ANY OTHER KEY TO CONTINUE\n\n\n\t\t\t\t";
		if(getch()=='X'||getch()=='x')
		{
			clrscr();
			cout<<"\n\n\n\n\n\n\t\t\t\tTHANKS FOR USING OUR SITE ";
			exit(0);
		}

		a:
		clrscr();
		cout<<"\n\n\n\n\n\n\t\t\t\tLOADING....";
		for(i=0.0;i<10000.0;i+=0.0001);
		ifstream filein;
		ifstream filin;
		filein.open("USER.TXT",ios::in);
		filin.open("PASSWORD.TXT",ios::in);
		filein.seekg(0);
		filin.seekg(0);
		char nm[25],pass[10];
		clrscr();
		cout<<"\t\t\t\t\t\twww.results@12.com"<<"\n\n\n\n\n\n\t\t\t\tLOG IN";
		cout<<"\n\n\t\t\t\tEnter name:";
		gets(nm);
		cout<<"\n\n\t\t\t\tEnter password(max.10 characters):";
		gets(pass);
		char line1[80],line2[80];
		int f=0;
		while((!filein.eof())&&(!filin.eof()))
		{
			filein.getline(line1,80,'\n');
			filin.getline(line2,80,'\n');
			if(!strcmpi(nm,line1)&&!strcmpi(pass,line2))
			{
				clrscr();
				f=1;
				cout<<"\n\n\n\n\n\n\t\t\t\tLOADING....";
				for(i=0.0;i<10000.0;i+=0.0001);
				break;

			}
			else if(!strcmpi(nm,line1)&&strcmpi(pass,line2))
			{
				clrscr();
				f=-1;
				cout<<"\n\n\n\n\t\t\tWRONG PASSWORD...TRY AGAIN";
				for(i=0.0;i<10000.0;i+=0.0001);
				break;
			}
		}

		filein.close();
		filin.close();

		if(f==-1)
			goto a;

		if(f==0)
		{
			clrscr();
			for(i=0.0;i<10000.0;i+=0.0001);
			ofstream fileout;
			ofstream filout;
			fileout.open("USER.TXT",ios::out|ios::ate);
			filout.open("PASSWORD.TXT",ios::out|ios::ate);
			cout<<"\t\t\t\t\t\twww.results@12.com\n\n\n\n\n\n\t\t\t\tNOT REGISTERED YET!!!!";
			cout<<"\n\n\t\t\t\tREGISTER NOW....";
			cout<<"\n\n\t\t\t\tEnter name:";
			gets(nm);
			fileout<<nm<<'\n';
			cout<<"\n\n\t\t\t\tEnter password(max.10 characters):";
			gets(pass);
			filout<<pass<<'\n';
			goto a;
		}

		char ch;
		int c=0;
		while (choice!=6)
		{
			clrscr();
			cout<<"\t\t\t\t\t\twww.results@12.com";
			cout<<"\n\n\n\t\t\t\tMAIN MENU";
			cout<<"\n\nPRESS 1 TO ENTER DATA INTO DATABASE\n";
			cout<<"PRESS 2 TO SEE RESULT OF INDIVIDUAL CANDIDATES\n";
			cout<<"PRESS 3 TO DELETE DATA FROM DATABASE\n";
			cout<<"PRESS 4 TO MODIFY DATA FROM DATABASE\n";
			cout<<"PRESS 5 TO SEE RESULTS BY (AS PER SPECIFICATION :SCHOOL,GRADE)\n";
			cout<<"PRESS 6 TO EXIT\n";
			cout<<"ENTER YOUR OPTION(1...6):";
			cin>>choice;
			for(i=0.0;i<10000.0;i+=0.0001);
			switch(choice)
			{
				case 1:
				clrscr();
				cout<<"\n\n\t\t\tYOU NEED TO KNOW SYSTEM CODE TO ENTER \n";
				cout<<"\n\n\t\t\tDO YOU KNOW THIS(Y/N):";
				cin>>ch;
				if(ch=='Y'||ch=='y')
				{
					add();
					cout<<"\n\n\t\t\tPRESS ANY KEY TO RETURN TO MAIN MENU:";
				}
				else
					break;
				getch();
				break;
				case 2:
				clrscr();
				search();
				cout<<"\n\n\t\t\tPRESS ANY KEY TO RETURN TO MAIN MENU:";
				getch();
				break;
				case 3:
				clrscr();
				cout<<"\n\n\t\t\tYOU NEED TO KNOW SYSTEM CODE TO ENTER \n";
				cout<<"\n\n\t\t\tDO YOU KNOW THIS(Y/N):";
				cin>>ch;
				if(ch=='Y'||ch=='y')
				{
					del();
					cout<<"\n\n\t\t\tPRESS ANY KEY TO RETURN TO MAIN MENU:";
				}
				else
					break;
				getch();
				break;
				case 4:
				clrscr();
				cout<<"\n\n\t\t\tYOU NEED TO KNOW SYSTEM CODE TO ENTER \n";
				cout<<"\n\n\t\t\tDO YOU KNOW THIS(Y/N):";
				cin>>ch;
				if(ch=='Y'||ch=='y')
				{
					mod();
					cout<<"\n\n\t\t\tPRESS ANY KEY TO RETURN TO MAIN MENU:";
				}
				else
            		break;
				getch();
				break;
				case 5:
				c=0;
				while(c!=3)
				{
					clrscr();
					cout<<"\t\t\t\t\t\twww.results@12.com";
					cout<<"\n\n\n\t\t\t\tSUB MENU";
					cout<<"\n\nPRESS 1 TO SEE RESULTS OF A PARTICULAR SCHOOL\n";
					cout<<"PRESS 2 TO SEE RESULTS GRADE WISE\n";
					cout<<"PRESS 3 TO RETURN TO MAIN MENU\n";
					cout<<"Enter your option(1...3):";
					cin>>c;
					switch(c)
					{
						case 1:
						clrscr();
						sorting_school();
						cout<<"\n\n\t\t\tPRESS ANY KEY TO RETURN TO SUB MENU:";
						getch();
						break;
						case 2:
						clrscr();
						sorting_grade();
						cout<<"\n\n\t\t\tPRESS ANY KEY TO RETURN TO SUB MENU:";
						getch();
						break;
						case 3:
						clrscr();
						break;
						default:
						clrscr();
					}
				}
				cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tPRESS ANY KEY TO RETURN TO MAIN MENU:";
				getch();
				break;
				case 6:
				clrscr();
				cout<<"\n\n\n\n\n\n\t\t\t\tTHANKS FOR USING OUR SITE ";
				break;
				default:
				clrscr();

			}
		}
	}
