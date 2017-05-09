//*Version 1.0*//
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <iostream>
#include <string>

#define Max 100

class Interface{
	private:

		//Call Back Function
		typedef void(*External_func)();
		External_func func[Max];

		string Program_name;
		string Function_List_Name[Max];
		string Function_List_Help[Max];
		int input;

	public:
		//Constructor & Destructor
		Interface(){
			input=-2;
			for(int i =0;i<=Max;i++){
				func[i]=NULL;
			}
		}
		~Interface(){}

		//Interface Function
		void Start(){
			cout<<"...Yapi Interface System..."<<endl;
			cout<<"-----------------------------"<<endl;
			cout<<"Program_name = "<<Program_name<<endl;
			ShowFunctionList();
			while(input!=-1){
				cout<<"command:";
				cin>>input;
				if(input==0){
					ShowFunctionList();
				}
				if(input==-1){
					return;
				}
				if(func[input]!=NULL){
					func[input]();
				}
			}
			return;
		}

		void ShowFunctionList(){
			int i=1;
			cout<<"\nFunction List:"<<endl;
			for(i=1;i<Max;i++){
				if(Function_List_Name[i].length()>0){
					cout<<"["<<i<<"] "<<Function_List_Name[i]<<endl;
					cout<<"   -"<<Function_List_Help[i]<<endl;
				}
			}
			cout<<"[-1] Exit	[0] Show Function List"<<endl;
			return ;
		}

		//Set & Get Variable Function
		bool SetListName(string name,int i){
			if(Function_List_Name[i].length()<=0){
				Function_List_Name[i]=name;
				return true;
			}else{
				cout<<"This Function Has Been Used"<<endl;
				return false;
			}
		}

		bool SetListHelp(string name,int i){
			if(Function_List_Help[i].length()<=0){
				Function_List_Help[i]=name;
				return true;
			}else{
				cout<<"This Function Has Been Used"<<endl;
				return false;
			}
		}

		bool SetFunc(External_func f,int i){
			if(func[i]==NULL && i>0){
				func[i] = f;
				return true;
			}else{
				cout<<"This Function Index Has Been Used"<<endl;
				return false;
			}
		}


		void SetProgramName(string name){
			Program_name = name;
			return ;
		}


};

#endif