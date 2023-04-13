#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
bool login();
int addstudent(string, int, int);
string* courses(int);

////////////////////////////////////////////////////////
///////STRUCTURE TO STORE ATTRIBUTES OF STUDENT/////////
////////////////////////////////////////////////////////

struct student{
	int rollNo;
	string name;
	int semester;
	int phoneNo;
	string* course;
	string grade_1,grade_2,grade_3;
	string attendence1, attendence2,attendence3;
	
};

student student_arr[100];          //ARRAY OF STUDENTS, WE CAN INCREASE OR NUMBER OF STUDENTS BY ITS PARAMETER
	
	int main() {
	bool flag=true;                //FLAG USED AS A FLOW CONTROLLER
	cout<<"///////////////////////////////////////////////\n";
	cout<<"/////WELCOME TO STUDENT MANAGEMENT SYSTEM//////\n";
	cout<<"///////////////////////////////////////////////\n";
	while(flag)
	{
		if(login()==true)          //LOGIN WILL GIVE TRUE IF THE CREDENTIALS ARE RIGHTS OTHERWISE IT WILL RETURN FALSE
		flag=false;
		else
		cout<<"WRONG CREDENTIALS \nTRY AGAIN";
	}
	flag=true;
	int check;
	while(flag)
	{
		cout<<"\n\n_____________________________MAIN MENU____________________________\n";
		cout<<"\nPRESS 1: ADD STUDENT IN SEMESTER\nPRESS 2: ADD GRADES\nPRESS 3: ADD ATTENDENCE\nPRESS 4: TO DISPALY ALL STUDENTS\nPRESS 5: TO SEE GRADES\nPRESS 6: TO SEE ATTENDENCE\nPRESS 0: TO EXIT\n";
		cin>>check;
		switch(check){
			case 0:{	
				flag=false;                                                //FLOW CONTROLER TO TERMINATE THE PROGRAM
				cout<<"_________________THANK YOU____________________";
				break;
			}
			case 1:{
				string name;
				int PH, semester;
				cout<<"ENTER NAME: ";
	            cin>>name;
	            cout<<"ENTER PHONE NUMBER: ";
	            cin>>PH;
	            cout<<"ENTER SEMESTER(1-8): ";
	            cin>>semester;
				int ROLL=addstudent(name,semester,PH);                  //ADD STUDENT ADD THE STUDENT IN ARRAY AND RETURN 
				cout<<"\n\n\n*********STUDNET REGISTERED SUCCESSFULLY**********\nROLL NUMBER ASSIGN IS: "<<ROLL<<"\n\n\n";
				break;
			}
			case 4:{
				for(int i=0;i<100;i++){
					if(!student_arr[i].name.empty()){
						cout<<"\nName : "<<student_arr[i].name;
						cout<<"\nROLL NUMBER: "<<student_arr[i].rollNo;
						cout<<"\nPhone number: "<<student_arr[i].phoneNo;
						cout<<"\nSEMESTER: "<<student_arr[i].semester;
				
						cout<<"\n*******REGISTERED COURSES********\n";
					    cout<<"COURSE# 1:"<<student_arr[i].course[0];
					    cout<<"\nCOURSE# 2:"<<student_arr[i].course[1];
					    cout<<"\nCOURSE# 3:"<<student_arr[i].course[2];
					    cout<<"\n____________________________________\n";
						}
						
					}
						break;
			}
			
			case 2:{
				int RN;string grade1,grade2,grade3;
				bool check1=true;
				cout<<"\nENTER STUDENT ROLL NO: ";
				cin>>RN;
				for(int k=0;k<100;k++){
					if(student_arr[k].rollNo==RN){
						cout<<"\n\nSTUDENT NAME: "<<student_arr[k].name<<"\nSTUDENT SEMESTER: "<<student_arr[k].semester;
						cout<<"\nSTUDENT COURSES: ";
						cout<<"\nCOURSE# 1:"<<student_arr[k].course[0];
					    cout<<"\nCOURSE# 2:"<<student_arr[k].course[1];
					    cout<<"\nCOURSE# 3:"<<student_arr[k].course[2];
					    cout<<"\n\nENTER GRADE OF COURSE # 1: ";
					    cin>>grade1;
					    cout<<"\n\nENTER GRADE OF COURSE # 2: ";
					    cin>>grade2;
					    cout<<"\n\nENTER GRADE OF COURSE # 3: ";
					    cin>>grade3;
					    student_arr[k].grade_1=grade1;
					    student_arr[k].grade_2=grade2;
					    student_arr[k].grade_3=grade3;
					    cout<<"\nGRADE ENTERED SUCCESSFULLY";
					    check1=false;
					    break;
					}
				}
				if(check1)
				cout<<"\nNO STUDENT FOUND";
				break;
			}
			
			case 5:{
				bool check2=true;
				int RN;
				cout<<"\nENTER ROLL NUMBER: ";
				cin>>RN;
				for(int k=0;k<100;k++){
					if(student_arr[k].rollNo==RN){
						cout<<"\n\nSTUDENT NAME: "<<student_arr[k].name<<"\nSTUDENT SEMESTER: "<<student_arr[k].semester;
						cout<<"\nGRADE OF COURSE "<<student_arr[k].course[0]<<" :"<<student_arr[k].grade_1;
						cout<<"\nGRADE OF COURSE "<<student_arr[k].course[1]<<" :"<<student_arr[k].grade_2;
						cout<<"\nGRADE OF COURSE "<<student_arr[k].course[2]<<" :"<<student_arr[k].grade_3;
						check2=false;
						break;
				    }
				}
				if(check2)
				cout<<"\nNO STUDENT FOUND";
				break;
			}
			
			case 3:{
				bool check3=true;
				int RN;string a1,a2,a3;
				cout<<"\nENTER ROLL NUMBER :";
				cin>>RN;
				for(int k=0;k<100;k++){
					if(student_arr[k].rollNo==RN){
					    cout<<"\n\nSTUDENT NAME: "<<student_arr[k].name<<"\nSTUDENT SEMESTER: "<<student_arr[k].semester;
						cout<<"\nSTUDENT COURSES: ";
						cout<<"\nCOURSE# 1:"<<student_arr[k].course[0];
					    cout<<"\nCOURSE# 2:"<<student_arr[k].course[1];
					    cout<<"\nCOURSE# 3:"<<student_arr[k].course[2];
					    cout<<"\nENTER ATTENDENCE OF COURSE# 1: ";
					    cin>>a1;
					    cout<<"\nENTER ATTENDENCE OF COURSE# 2: ";
					    cin>>a2;
					    cout<<"\nENTER ATTENDENCE OF COURSE# 3: ";
					    cin>>a3;
					    student_arr[k].attendence1=a1;
					    student_arr[k].attendence2=a2;
					    student_arr[k].attendence3=a3;
					    cout<<"\nATTENDENCE ADD SUCCESSFULLY";
					    check3=false;
					    break;
					}
				}
				if(check3)
				cout<<"NO STUDENT FOUND";
				break;
			}
			case 6:{
				bool check4=true;
				int RN;
				cout<<"\nENTER ROLL NUMBER: ";
				cin>>RN;
				for(int k=0;k<100;k++){
					if(student_arr[k].rollNo==RN){
						cout<<"\n\nSTUDENT NAME: "<<student_arr[k].name<<"\nSTUDENT SEMESTER: "<<student_arr[k].semester;
						cout<<"\nATTENDENCE OF COURSE "<<student_arr[k].course[0]<<" :"<<student_arr[k].attendence1;
						cout<<"\nATTENDENCE OF COURSE "<<student_arr[k].course[1]<<" :"<<student_arr[k].attendence2;
						cout<<"\nATTENDENCE OF COURSE "<<student_arr[k].course[2]<<" :"<<student_arr[k].attendence3;
						check4=false;
						break;
				    }
				}
				if(check4)
				cout<<"\nNO STUDENT FOUND";
				break;
			}
			
			
			
			}
			}
		}
				
/////////////////////////////////////////////
/////RETURN REFERENCE OF ARRAY OF COURSES////
/////////////////////////////////////////////
string* courses(int i){
	static string arr1[3];
	static string arr2[3];
	static string arr3[3];
	static string arr4[3];
	static string arr5[3];
	static string arr6[3];
	static string arr7[3];
	static string arr8[3];
	switch(i){
		case 1:{
			arr1[0]="CP104";              //COURSES OF SEMESTER 1, WE CAN CHANGE COURSES FROM HERE
			arr1[1]="MT103";          
			arr1[2]="CS201";
			return arr1;
			break;
		}
		case 2:{
			arr2[0]="CCS04";
			arr2[1]="M2303";
			arr2[2]="C4401";
			return arr2;
			break;
		}
		case 3:{
			arr3[0]="CC404";
			arr3[1]="MR503";
			arr3[2]="AIE01";
			return arr3;
			break;
		}
		case 4:{
			arr4[0]="C1204";
			arr4[1]="MTW03";
			arr4[2]="C2301";
			return arr4;
			break;
		}
		case 5:{
			arr5[0]="CP204";
			arr5[1]="MT203";
			arr5[2]="CS301";
			return arr5;
			break;
		}
		case 6:{
			arr6[0]="CP504";
			arr6[1]="MT503";
			arr6[2]="CS501";
			return arr6;
			break;
		}
		case 7:{
			arr7[0]="CP604";
			arr7[1]="MT603";
			arr7[2]="CS601";
			return arr7;
			break;
		}
		case 8:{
			arr8[0]="CP704";
			arr8[1]="MT803";
			arr8[2]="CS701";
			return arr8;
			break;
		}
		
	}
	return 0;

		
}

int addstudent(string Name, int sem, int phonenumber){
	int i;
	for(i=0;i<100;i++){
		if(student_arr[i].name.empty()){
			student_arr[i].rollNo=i;
			student_arr[i].phoneNo=phonenumber;
			student_arr[i].name=Name;
			student_arr[i].semester=sem;
			student_arr[i].course=courses(sem);
			break;
		}	
	}
	return i;
}

bool login()
{
   string id,pass,ID,PASS;
   ofstream newfile("loginn.txt");         // FILE WRITING
      newfile<<"talha@gmail.com\n12345";   //WE CAN CHANGE EMAIL AND PASS FROM HERE
      newfile.close();
	  string temp;
	  int k=0;
      ifstream Read("loginn.txt");         //FILE READING
      while (getline (Read, temp)) {
      	      if(k==0){
              id=temp;
               k++;
              }
	          else 
	          pass=temp;
      
}
Read.close();

	cout<<"\nENTER LOGIN : ";
	cin>>ID;
	cout<<"ENTER PASS : ";
	cin>>PASS;
	if(id==ID&&PASS==pass)
	return true;
	else 
	return false;	
}










         