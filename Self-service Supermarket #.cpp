/*
this is a system used by owner for service supermarket
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#define code 0
#define name 1
#define price 2
#define quantity 3
#define loca 0
#define sec 1
#define ais 2
#define shelf 3

using namespace std;

void AddNewProduct();
void AddNewLocation();
void Search();
void Display();
void Delet();
void update();
void Remove();
int ctr_product=0;
int ctr_location=0;
string Product[50][4];//50 number of product that the user will enter it and 4 number of charctristic
string location[50][4];
int i=1;
 
 ofstream file;
 
  
 int main(){
 	
 	int choice,p,flag=1;
 	
 	cout<<"========================\n SUPERMARKET SYSTEM \n========================\n";
	cout<<endl;
	cout << "*Enter the password to open the system*: ";
	cin >> p;
    cout<<endl;
    
while (p!=0000){
cout << "Wrong password!\n";
cout<<"*Enter the correct password to open the system*: ";
cin>>p;
cout<<endl;
}
	system("cls");//.... it is to clean the console

	cout<<"============\n WELCOME \n============\n";
	cout<<endl;
    cout << " Press[1] to Add a new product.\n";
	cout << " Press[2] to Add a new location.\n";
	cout << " Press[3] to Search about product/location.\n";
	cout << " Press[4] to Display a product/location.\n";
	cout << " Press[5] to Delete a product/location.\n";
	cout << " Press[6] to Update a product/location.\n";
	cout << " press[7] to Remove product/location from location/product details.\n";
    cout << " Press[0] or any litter to Quit\n";
	  
    cout<<" Please enter your choice: ";
  	cin>>choice;
	  while( choice < 0 || choice > 7)
	{
		cout << "Please select a number according to the processes above: \n";
		cin >> choice;
	}
  	if(choice==0){
  		flag=0;
  		cout<<"\n"<<endl;
  		cout<<"                  ================\n                      GOODBYE \n                  ================";
  		cout<<"\n"<<endl;
	  }
  	else{
	  
 	while(flag){

 	switch(choice){
 		
 	case 1:
	 AddNewProduct();	
	break;
	
	case 2:
	 AddNewLocation();
	break;
	
	case 3:
	 Search();
	break;
	
	case 4:
	Display();
	break;
		
	case 5:
	Delet();
	break;
	
	case 6:
	update();
	break;
	
	case 7:
    Remove();
	break;	
	default:
		cout<<"Please select a number according to these processes: \n";
	break;
  	
 }
 cout<<endl;
 cout<<"========================\n SUPERMARKET SYSTEM \n========================\n";
	cout<<endl;
cout << " Press[1] to Add a new product.\n";
	cout << " Press[2] to Add a new location.\n";
	cout << " Press[3] to Search about product/location.\n";
	cout << " Press[4] to Display a product/location.\n";
	cout << " Press[5] to Delete a product/location.\n";
	cout << " Press[6] to Update a product/location.\n";
	cout << " press[7] to Remove product/location from location/product details.\n";
    cout << " Press[0] to Quit or any litter\n";
	cout << " Please enter your choice : ";  
  	cin>>choice;
  	if(choice==0){
  		flag=0;
  		cout<<"\n"<<endl;
  		cout<<"                  ================\n                      GOODBYE \n                  ================";
  		cout<<"\n"<<endl;
		    }

}
}

 return 0;}
 
 
 // add product function: alow the user to add new product 

void AddNewProduct(){
	
	cout<<"=====================\n ADDING PRODUCT \n====================\n";
	cout<<endl;
	cout<<"\n*ONLY 50 PRODUCTS ALLOWED*\n\n";
	file.open("Product.txt",ios::app);
	if(ctr_product==50){
		cout<<" \n Sorrey 50 products is maximum , You can not add a new product\n"<<endl;
	}
if(Product[ctr_product][code]==" " &&Product[ctr_product][name]==" " &&Product[ctr_product][price]==" " &&Product[ctr_product][quantity]==" "){
	cout<<"Enter a code number for  product "<<ctr_product<<": \n";
	cin>>Product[ctr_product][code];
	
	cout<<"Type a name for  prodect "<<ctr_product << "(Please enter the name like this:lemon_juice)"<<": \n";
	cin>>Product[ctr_product][name];
	
	cout<<"Enter a price for prodect "<<ctr_product<<": \n";
	cin>>Product[ctr_product][price];

	cout<<"Enter the quantity for product "<<ctr_product<<": \n";
	cin>>Product[ctr_product][quantity];
	
	file<<"=============="<<endl;
	file<<"CODE"<<"     "<<"NAME"<<"     "<<"PRICE"<<"        "<<"QUANTITY"<<endl;
	//file<<"=============="<<endl;
	file<<Product[ctr_product][code]<<"                 "<<Product[ctr_product][name]<<"       "<<Product[ctr_product][price]<<"  "<<Product[ctr_product][quantity]<<endl;
	ctr_product++;}
	else{
			cout<<"Enter a code number for product "<<ctr_product+1<<": \n";
	cin>>Product[ctr_product][code];
	
	cout<<"Type a name for prodect "<<ctr_product+1 <<"(Please enter the name like this:lemon_juice) "<<": \n";
	cin>>Product[ctr_product][name];
	
	cout<<"Enter a price for prodect "<<ctr_product+1<<": \n";
	cin>>Product[ctr_product][price];

	cout<<"Enter the quantity for product "<<ctr_product+1<<": \n";
	cin>>Product[ctr_product][quantity];
	
	file<<"=============="<<endl;
	file<<"CODE"<<"     "<<"NAME"<<"     "<<"PRICE"<<"        "<<"QUANTITY"<<endl;
	//file<<"=============="<<endl;
	file<<Product[ctr_product][code]<<"      "<<Product[ctr_product][name]<<"       "<<Product[ctr_product][price]<<"        "<<Product[ctr_product][quantity]<<endl;
	ctr_product++;
	file.close();
	
	}

	system("pause");//this will work on window's OS , it to give a user the chance to read
	system("cls");//.... it is to clean the console
}

//_______________________________________________________________________________________________________________________________________________________

//--------------------------------------------------------------------------------------------------------------new function

//add location function: alows the user to add location to the prodect sequentially

void AddNewLocation(){
	cout<<"=====================\n ADDING LOCATION \n====================\n";
	cout<<endl;
	
	cout<<"\n*ONLY 50 LOCATION ALLOWED*\n\n";
	file.open("Location.txt",ios::app);//app used to add information to the file
	if(ctr_location==50){
		cout<<" \n Sorrey 50 locations is maximum , You can not add a new location\n"<<endl;
	}
	if(location[ctr_location][loca]==" " &&location[ctr_location][sec]==" " &&location[ctr_location][ais]==" " &&location[ctr_location][shelf]==" "){
	cout<<"Enter a number for location "<<ctr_location<<" of product "<<i<<":\n";
	cin>>location[ctr_location][loca];
	
	cout<<"Type a section name for location "<<ctr_location<<" of product "<<i<<" (Please enter the name like this: drinks_section)" <<":\n";
	cin>>location[ctr_location][sec];
	
	cout<<"Enter a aisle number for a location "<<ctr_location<<" of product "<<i<<":\n";
	cin>>location[ctr_location][ais];
	
	cout<<"Enter a shelf number for a location "<<ctr_location<<" of product "<<i<<":\n";
	cin>>location[ctr_location][shelf];
	
	file<<"NUMBER FOR LOCATION"<<"     "<<"SECTION NAME"<<"*|*"<<"AISLE"<<"*|*"<<"SHELF"<<"*|*\n";//to write in side the file
	file<<"*|*"<<location[ctr_location][loca]<<"*|*"<<location[ctr_location][sec]<<"*|*"<<location[ctr_location][ais]<<"*|*"<<location[ctr_location][shelf]<<"*|*"<<endl;
    i++;
	ctr_location++;}
	
	else{
		cout<<"Enter a number for location "<<ctr_location+1<<" of product "<<i<<":\n";
	cin>>location[ctr_location][loca];
	
	cout<<"Type a section name for a location "<<ctr_location+1<<" of product "<<i<<"(Please enter the name like this: drinks_section) "<<":\n";
	cin>>location[ctr_location][sec];
	
	cout<<"Enter a aisle number for a location "<<ctr_location+1<<" of product "<<i<<":\n";
	cin>>location[ctr_location][ais];
	
	cout<<"Enter a shelf number for a location "<<ctr_location+1<<" of product "<<i<<":\n";
	cin>>location[ctr_location][shelf];
	
	file<<"=============="<<endl;
	file<<"NUMBER FOR LOCATION"<<"      "<<"SECTION NAME"<<"      "<<"AISLE"<<"      "<<"SHELF"<<endl;//to write in side the file
	file<<location[ctr_location][loca]<<"                     "<<location[ctr_location][sec]<<"        "<<location[ctr_location][ais]<<"        "<<location[ctr_location][shelf]<<"    "<<endl;
i++;
     ctr_location++;
	}
	
	file.close();
	system("pause");
	system("cls");
}//--------------------------------------------------------------------------------------------------end function

//_______________________________________________________________________________________________________________________________________________________

//--------------------------------------------------------------------------------------------------------------new function
//search function alows the user to choose the search method and use any information available to him in order to find the desired product/location .
//in case the function do not find the product/location ,A message will appear to the user that say(the product/location can not be found



void Search(){

cout<<"=====================\n SEARCHING \n====================\n";
	cout<<endl;
	 
int counter1,counter2,choice,ch,a,flag=1;;
string code_num,pro_name,pro_price,pro_quantity,shelf_num,sec_name,ais_num,num_L;

cout<<"...Enter [1] to search using product information...[2] to search using location information...\n";//-------------------choose the search method
cout<<"Your choice:";
cin>>choice;

switch (choice){
case 1:	//---------------------------------------------------------------------------------------------------------------- part 1 to search using product information
	if(ctr_product==0){// ----------------------------------------------------------------------searching linked to prodect so we need to check if there is a prodect or no
	cout<<"\nSorry There is no product !\n";
	system("pause");
	system("cls");}	


else {
	
	cout<<"Press [1] to search by using product's code \nPress [2] to search by using product's name\nPress [3] to search by using product's price \nPress [4] to search by using  product's quantity\n";
	cout<<"Please enter your choice:";
	cin>>ch;
switch(ch){
	
case 1:
cout<<"\nPlease enter the product's code :";

cin>>code_num;
cout<<endl;
for(counter1=0;counter1<=ctr_product;counter1++){//---------------------------------------------print all information
		if(code_num==Product[counter1][code]){
			
			
		
		cout<<" *** PRODUCT'S CODE *** PRODUCT'S NAME *** PRICE *** QUANTITY *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER ***\n";
		cout<<setw(16)<<Product[counter1][code]<<setw(15)<<Product[counter1][name]<<setw(16)<<Product[counter1][price]<<setw(13)<<Product[counter1][quantity]<<setw(15)<<location[counter1][loca]<<setw(18)<<location[counter1][sec]<<setw(16)<<location[counter1][ais]<<setw(17)<<location[counter1][shelf]<<endl;
		flag=0;
		break;//--------------------------------------------------to exit if after found the code
		}	

	}//-----------------------------------end for
	
if(flag==1){

	cout<<"\n\nSorry the product can not be found !\n";
	cout<<"There is no product that has this code : "<<code_num<<endl; 
}
system("pause");
	system("cls");		
break;	
case 2:
	
cout<<"\nPlease enter the product's name :";

cin>>pro_name;
cout<<endl;

for(counter1=0;counter1<=ctr_product;counter1++){//---------------------------------print all information
		if(pro_name==Product[counter1][name]){
		
		cout<<" *** PRODUCT'S CODE *** PRODUCT'S NAME *** PRICE *** QUANTITY *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER ***\n";
		cout<<setw(16)<<Product[counter1][code]<<setw(15)<<Product[counter1][name]<<setw(16)<<Product[counter1][price]<<setw(13)<<Product[counter1][quantity]<<setw(15)<<location[counter1][loca]<<setw(18)<<location[counter1][sec]<<setw(16)<<location[counter1][ais]<<setw(17)<<location[counter1][shelf]<<endl;
	flag=0;
		break;
		
}	

}//--------------------------------------------end for

if (flag==1){

cout<<"\n\nSorry the product can not be found !\n";
cout<<"There is no product that has this name : "<<pro_name<<endl; 		
}
system("pause");
	system("cls");
break;
case 3:
	
cout<<"\nPlease enter the product's price :";

cin>>pro_price;
cout<<endl;

for(counter1=0;counter1<=ctr_product;counter1++){//--------------------------print all information
		if(pro_price==Product[counter1][price]){
			
			
		
		cout<<" *** PRODUCT'S CODE *** PRODUCT'S NAME*** PROCE *** QUANTITY *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER ***\n";
		cout<<setw(16)<<Product[counter1][code]<<setw(15)<<Product[counter1][name]<<setw(16)<<Product[counter1][price]<<setw(13)<<Product[counter1][quantity]<<setw(15)<<location[counter1][loca]<<setw(18)<<location[counter1][sec]<<setw(16)<<location[counter1][ais]<<setw(17)<<location[counter1][shelf]<<endl;
	
		flag=0;
		break;}//--------------------------end if 
			

	
}//----------------------------------end for
if (flag==1){
	cout<<"\n\nSorry the product can not be found !\n";
	cout<<"There is no product that has this price : "<<pro_price<<endl; 
}
		
system("pause");
	system("cls");
break;
case 4:

cout<<"\nPlease enter the product's quantity :";

cin>>pro_quantity;
cout<<endl;

for(counter1=0;counter1<=ctr_product;counter1++){//--------------------------------print all information
		if(pro_quantity==Product[counter1][quantity]){
			
			
		
			cout<<" *** PRODUCT'S CODE *** PRODUCT'S NAME *** PRICE *** QUANTITY *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER ***\n";
		cout<<setw(16)<<Product[counter1][code]<<setw(15)<<Product[counter1][name]<<setw(16)<<Product[counter1][price]<<setw(13)<<Product[counter1][quantity]<<setw(15)<<location[counter1][loca]<<setw(18)<<location[counter1][sec]<<setw(16)<<location[counter1][ais]<<setw(17)<<location[counter1][shelf]<<endl;
	flag=0;
		break;}//-----------------------------end if 
			
}//--------------------------------------end for
if(flag==1){
	cout<<"\n\nSorry the product can not be found !\n";
	cout<<"There is no product that has this quantity : "<<pro_quantity<<endl; 
}
system("pause");
	system("cls");	
		break;
default:
cout<<"invalid\n";
system("pause");
	system("cls");
	break;
}//end switch for case 1----
}//end else in case 1 which related to the outer switch
//--------------------------------------------------------------------------------------------------------part 2 to search using location information
break;
	 case 2:
	
if(ctr_location==0){//-----------------------------------------------------searchin linked to location so we need to check if there is alocation or no
	cout<<"\nSorry There is no location!\n";
	system("pause");
	system("cls");
	}
	
	else {
		cout<<"Press [1] to search using a location's number'\nPress [2] to search using a section name \nPress [3] to search using a aisle number \nPress [4] to search using a shelf number \n";
	cout<<"Please enter your choice:";
	cin>>a;
	switch(a){
		
		case 1:
			
		cout<<"\nPlease enter the location number:";
		cin>>num_L;
		cout<<endl;
	for(counter2=0;counter2<ctr_location;counter2++){//----------------------------print all information
		if(num_L==location[counter2][loca]){
			
			
		
		
			cout<<" *** PRODUCT'S CODE *** PRODUCT'S NAME *** PRICE *** QUANTITY *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER ***\n";
		cout<<setw(16)<<Product[counter2][code]<<setw(15)<<Product[counter2][name]<<setw(16)<<Product[counter2][price]<<setw(13)<<Product[counter2][quantity]<<setw(15)<<location[counter2][loca]<<setw(18)<<location[counter2][sec]<<setw(16)<<location[counter2][ais]<<setw(17)<<location[counter2][shelf]<<endl;
	flag=0;
		break;
		
}//---------------end if

}//-------------------end for
if(flag==1){

	cout<<"\n\nSorry the location can not be found !\n";
	cout<<"There is no location  that has this number: "<<num_L<<endl;
}
system("pause");
	system("cls");
 break;
 case 2:
 	cout<<"\nPlease enter the section name:";
		cin>>sec_name;
		cout<<endl;
	for(counter2=0;counter2<ctr_location;counter2++){//-------------------------------------print all information
		if(sec_name==location[counter2][sec]){
			
			cout<<" *** PRODUCT'S CODE *** PRODUCT'S NAME *** PRICE *** QUANTITY *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER ***\n";
		cout<<setw(16)<<Product[counter2][code]<<setw(15)<<Product[counter2][name]<<setw(16)<<Product[counter2][price]<<setw(13)<<Product[counter2][quantity]<<setw(15)<<location[counter2][loca]<<setw(18)<<location[counter2][sec]<<setw(16)<<location[counter2][ais]<<setw(17)<<location[counter2][shelf]<<endl;
	flag=0;
		break;
			
}//end if---


}//end for---
if(flag==1){

	cout<<"\n\nSorry the location can not be found !\n";
	cout<<"There is no section that has this name: "<<sec_name<<endl; 
}
system("pause");
	system("cls");
break;
case 3:
	cout<<"\nPlease enter the aisle number:";
		cin>>ais_num;
		cout<<endl;
	for(counter2=0;counter2<ctr_location;counter2++){//----------------------------------print all information
		if(ais_num==location[counter2][ais]){
		
	
			cout<<" *** PRODUCT'S CODE *** PRODUCT'S NAME *** PRICE *** QUANTITY *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER ***\n";
		cout<<setw(16)<<Product[counter2][code]<<setw(15)<<Product[counter2][name]<<setw(16)<<Product[counter2][price]<<setw(13)<<Product[counter2][quantity]<<setw(15)<<location[counter2][loca]<<setw(18)<<location[counter2][sec]<<setw(16)<<location[counter2][ais]<<setw(17)<<location[counter2][shelf]<<endl;
	flag=0;
		break;
	
			
}//----------------end if

}//------------------end for
if(flag==1){

cout<<"\n\nSorry the location can not be found !\n";
	
cout<<"There is no location that has this aisle : "<<ais_num<<endl; 
}
system("pause");
	system("cls");
break;
case 4:
	cout<<"\nPlease enter the shelf number:";
		cin>>shelf_num;
		cout<<endl;
	for(counter2=0;counter2<ctr_location;counter2++){//------------------------------------print location
		if(shelf_num==location[counter2][shelf]){
			
			cout<<" *** PRODUCT'S CODE *** PRODUCT'S NAME *** PRICE *** QUANTITY *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER ***\n";
		cout<<setw(16)<<Product[counter2][code]<<setw(15)<<Product[counter2][name]<<setw(16)<<Product[counter2][price]<<setw(13)<<Product[counter2][quantity]<<setw(15)<<location[counter2][loca]<<setw(18)<<location[counter2][sec]<<setw(16)<<location[counter2][ais]<<setw(17)<<location[counter2][shelf]<<endl;
	flag=0;
		break;
			
}//------------------end if
}//---------------------end for
if(flag==1){
	cout<<"\n\nSorry the location can not be found !\n";
	cout<<"There is no location that has this shelf : "<<shelf_num<<endl;
}
system("pause");
	system("cls");
	break;
	
	default:
cout<<"invalid\n";
system("pause");
	system("cls");
	break;
	}//---------------------------------------------------------------end switch in case2 which related to outer switch
}//--------------------------------------------------------------------end else in case 2 which is related to the outer switch
break;

default:
	

	cout<<"Invalid!\n";	
system("pause");
	system("cls");

}//--------------------------------------end outer switch
}//--------------------------------------end function serach

//_______________________________________________________________________________________________________________________________________________________

//--------------------------------------------------------------------------------------------------------------new function
//showing funcyion: allow the user to display all information stored in the system 

		
void Display(){
	cout<<"=====================\n SHOWING \n====================\n";
	cout<<endl;

	int counter1,counter2,choice;

cout<<"...Enter [1] to display the products just         [2]... to display the locations just...         [3]...to display all...\n";
cout<<"\n Your choice: ";
cin>>choice;
		switch(choice){
			
			case 1:
				
		if(ctr_product==0)
		cout<<"Sorry there is no product to display!\n"<<endl;
	else{
				
	cout<<"_______________________________________________________________________________\n";	
	cout<<" *** PRODUCT'S CODE *** PRODUCT'S NAME *** PRICE *** QUANTITY ***\n";
	for(counter1=0;counter1<=ctr_product;counter1++){//-------------print product information 
		
		
	
		cout<<setw(15)<<Product[counter1][code]<<setw(15)<<Product[counter1][name]<<setw(15)<<Product[counter1][price]<<setw(15)<<Product[counter1][quantity]<<endl;
		
}//----end for
}//end else
system("pause");
	system("cls");
break;
			
	case 2:
		if(ctr_location==0){
			cout<<"Sorry there is no location to display!\n"<<endl;
				
		}
	else{
		
			cout<<"_____________________________________________________________________________\n";
		cout<<" *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER *** "<<endl;
	for(counter2=0;counter2<ctr_location;counter2++){//print location
		 
		
		
	
		cout<<setw(15)<<location[counter2][loca]<<setw(15)<<location[counter2][sec]<<setw(15)<<location[counter2][ais]<<setw(15)<<location[counter2][shelf]<<endl;
		
}//----end for
}
system("pause");
	system("cls");
break;
case 3:
	
	 if(ctr_product==0&&ctr_location==0){//----------------because it linked to prodect/location so we need to check if there is a prodect/locayion or not
	cout<<"\nSorry there is no item to display !\n"<<endl;
		}
		
	else if(ctr_product!=0||ctr_location!=0)	{
cout<<"____________________________________________________________________________________________________________________________________________________\n";	
	cout<<" *** PRODUCR'S CODE *** PRODUCT'S NAME *** PRICE *** QUANTITY *** LOCATION NUMBER *** SECTION NAME *** AISLE NUMBER *** SHELF NUMBER ***\n";
	for(counter1=0,counter2=0;counter1<=ctr_product||counter2<=ctr_location;counter1++,counter2++)
	cout<<setw(15)<<Product[counter1][code]<<setw(15)<<Product[counter1][name]<<setw(15)<<Product[counter1][price]<<setw(15)<<Product[counter1][quantity]<<setw(15)<<location[counter2][loca]<<setw(17)<<location[counter2][sec]<<setw(17)<<location[counter2][ais]<<setw(17)<<location[counter2][shelf]<<endl;
		
}//------------------------------------------end else
	system("pause");
	system("cls");
break;
default	:
cout<<"\ninvalid!\n";
system("pause");
	system("cls");
	break;	
}//end s
		
}//------------------------------------------------------------------------------------------end function
  
//_______________________________________________________________________________________________________________________________________________________

//--------------------------------------------------------------------------------------------------------------new function
//........ the function allow the user to delete a product /location records by using any information available to him
void Delet()
{
	cout<<"=====================\n DELETING \n====================\n";
	cout<<endl;
	
	int s,a,b,x,p,flag=1,d;
	string code_num,name_pro,pric,quantit,num_L,name_lo,shel,ai;
	cout<<"...Enter [1] to delete product [2]... to delete location...\n";
	cin>>d;
	switch(d){
	
	case 1:
	if(ctr_product==0){
	 	
	 cout<<"\n Sorry there is no product to delete it!\n";
	 system("pause");
	system("cls");	
		
	 }
	 else{
	cout<<"chooes the way to find the desired product :\n[1]code\n[2]name\n[3]price\n[4]quantity\n";
	cout<<"your choice:";
	cin>>b;
	switch(b){
		case 1:
	cout<<"Enter the product code\n";
	cin>>code_num;
	for(int i=0;i<=ctr_product;i++){
		if(code_num==Product[i][code]){
			flag=0;
		Product[i][code]=Product[i+1][code];
	Product[i+1][code]=" ";
	Product[i][name]=Product[i+1][name];
	Product[i+1][name]=" ";
	Product[i][price]=Product[i+1][price];
	Product[i+1][price]=" ";
	Product[i][quantity]=Product[i+1][quantity];
	Product[i+1][quantity]=" ";
	ctr_product--;	
	cout<<"\n *DONE*\n";

}//if
}//for
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;		
system("pause");
	system("cls");	}
break;
	
case 2:
		cout<<"Enter the product name\n";
	cin>>name_pro;
	for(int i=0;i<=ctr_product;i++){
		if(name_pro==Product[i][name]){
			flag=0;
		Product[i][code]=Product[i+1][code];
	Product[i+1][code]=" ";
	Product[i][name]=Product[i+1][name];
	Product[i+1][name]=" ";
	Product[i][price]=Product[i+1][price];
	Product[i+1][price]=" ";
	Product[i][quantity]=Product[i+1][quantity];
	Product[i+1][quantity]=" ";
	ctr_product--;	
	cout<<"\n *DONE*\n";
}//end if
	
}//end for
	if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;		
system("pause");
	system("cls");	}
break;

case 3:

cout<<"Enter the product price\n";
	cin>>pric;
	for(int i=0;i<=ctr_product;i++){
		if(pric==Product[i][price]){
			flag=0;
		Product[i][code]=Product[i+1][code];
	Product[i+1][code]=" ";
	Product[i][name]=Product[i+1][name];
	Product[i+1][name]=" ";
	Product[i][price]=Product[i+1][price];
	Product[i+1][price]=" ";
	Product[i][quantity]=Product[i+1][quantity];
	Product[i+1][quantity]=" ";
	ctr_product--;	
	cout<<"\n *DONE*\n";
}//endif
}//end for
	if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
system("pause");
	system("cls");
}
break;

case 4:
	cout<<"Enter the product quantity\n";
	cin>>quantit;
	for(int i=0;i<=ctr_product;i++){
		if(quantit==Product[i][quantity]){
			flag=0;
		Product[i][code]=Product[i+1][code];
	Product[i+1][code]=" ";
	Product[i][name]=Product[i+1][name];
	Product[i+1][name]=" ";
	Product[i][price]=Product[i+1][price];
	Product[i+1][price]=" ";
	Product[i][quantity]=Product[i+1][quantity];
	Product[i+1][quantity]=" ";
	ctr_product--;	
	cout<<"\n *DONE*\n";
}//end if
}//end for
	if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
system("pause");
	system("cls");
}
break;

default:
cout<<"\ninvalid\n";	
}//end switch
}//end else

break;

case 2:

	if(ctr_location==0){
	 	
	 cout<<"\n Sorry there is no location to delete it!\n";
	 system("pause");
	system("cls");	
	
	 }
	 else{
	cout<<"chooes the way to find the desired location :\n [1]location number\n[2]section name\n[3]aisle\n[4]shelf\n";
	cout<<"your choice:";
	cin>>b;
	 	
	switch(b){
	 		
	case 1:
	 			
	cout<<"Enter the location number \n";
	cin>>num_L;
	for(int j=0;j<=ctr_location;j++){
		if(num_L==location[j][code]){
			flag=0;
	location[j][loca]=location[j+1][loca];
	location[j+1][loca]=" ";
	location[j][sec]=location[j+1][sec];
	location[j+1][sec]=" ";
	location[j][ais]=location[j+1][ais];
	location[j+1][ais]=" ";
	location[j][shelf]=location[j+1][shelf];
	location[j+1][shelf]=" ";
	ctr_location--;
	cout<<"\n *DONE*\n";
}//if
}//for
	if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
system("pause");
	system("cls");
}
break;

case 2:
	cout<<"Please enter the section name \n ";
		cin>>name_lo;
	for(int j=0;j<=ctr_location;j++){
		if(name_lo==location[j][name]){
			flag=0;
		location[j][loca]=location[j+1][loca];
	location[j+1][loca]=" ";
	location[j][sec]=location[j+1][sec];
	location[j+1][sec]=" ";
	location[j][ais]=location[j+1][ais];
	location[j+1][ais]=" ";
	location[j][shelf]=location[j+1][shelf];
	location[j+1][shelf]=" ";
	ctr_location--;
	cout<<"\n *DONE*\n";
}//if
	
}//end for
	 		
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
system("pause");
	system("cls");}
break;
	
case 3:
	cout<<"Please enter the aisle number of location\n ";
		cin>>ai;
	for(int j=0;j<=ctr_location;j++){
		if(ai==location[j][ais]){
			flag=0;
	location[j][loca]=location[j+1][loca];
	location[j+1][loca]=" ";
	location[j][sec]=location[j+1][sec];
	location[j+1][sec]=" ";
	location[j][ais]=location[j+1][ais];
	location[j+1][ais]=" ";
	location[j][shelf]=location[j+1][shelf];
	location[j+1][shelf]=" ";
	ctr_location--;
	cout<<"\n *DONE*\n";
}//if
}//end for	 		
	 		
	 
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
system("pause");
	system("cls");}
break;		

 case 4:
 cout<<"Pease enter the shelf number of location\n ";
		cin>>shel;
		
		for(int j=0;j<=ctr_location;j++){
			if(shel==location[j][shelf]){
			flag=0;
	location[j][loca]=location[j+1][loca];
	location[j+1][loca]=" ";
	location[j][sec]=location[j+1][sec];
	location[j+1][sec]=" ";
	location[j][ais]=location[j+1][ais];
	location[j+1][ais]=" ";
	location[j][shelf]=location[j+1][shelf];
	location[j+1][shelf]=" ";
	ctr_location--;
	cout<<"\n *DONE*\n";
}//if
}//end for	 		
	 			 
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
system("pause");
	system("cls");
}
break;				 

default:
cout<<"\ninvalid\n";		 
}//end switch
}//end else

break;
default:
cout<<"invalid!\n"<<endl;
system("pause");
	system("cls");
	}//end main s
}

//_______________________________________________________________________________________________________________________________________________________

//--------------------------------------------------------------------------------------------------------------new function
//..........this function allow the user to update all or  single information in a product /location records by using any information available to him
 

void update(){
cout<<"=====================\n UPDATING \n====================\n";
	cout<<endl;	
	int s,a,b,flag=1,d;
	string code_num,name_pro,pric,quantit,num_L,name_lo,shel,ai;
	
		cout<<"...Enter [1] to update product [2]... to update location...\n";
	cin>>d;
	switch(d){
		case 1:{
		
	if(ctr_product==0){
	 	
	 cout<<"\n Sorry there is no product to update it!\n";
	 system("pause");
	system("cls");	}
	
	else{//----else 
	cout<<"chooes the way to find the desired product :\n[1]code\n[2]name\n[3]price\n[4]quantity\n";
	cout<<"your choice:";
	cin>>b;
	switch(b){
		
	case 1:
	cout<<"Please enter the product code\n";
	cin>>code_num;
	for(int i=0;i<=ctr_product;i++){
		if(code_num==Product[i][code]){
			flag=0;
	cout<<"Press [1] to update a code of product\nPress [2] to update a name of product\nPress [3] to update a price of product\nPress [4] to update the quantity of product\nPress [5] to update all\nYour choice :";
	cin>>a;
	
		switch(a){//-----------switch 
		case 1:
	cout<<"Enter a new code for a product \n";
	cin>>Product[i][code];
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	cout<<"Type a new name for a prodect \n";
	cin>>Product[i][name];
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	cout<<"Enter a new price for a prodect \n";
	cin>>Product[i][price];
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	cout<<"Enter a new quantity for a products \n";
	cin>>Product[i][quantity];
	cout<<"\n*DONE*\n";
	break;
	case 5:
	cout<<"Enter a new code for a product \n";
	cin>>Product[i][code];
	cout<<"Type a new name for a prodect \n";
	cin>>Product[i][name];
	cout<<"Enter a new price for a prodect \n";
	cin>>Product[i][price];
	cout<<"Enter a new quantity for a products \n";
	cin>>Product[i][quantity];	

	cout<<"\n*DONE*\n";
	break;
	default:
		
		cout<<"invalid!\n"<<endl;
		break;

	}//end switch num1	
}//end if
}//end for

if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;

case 2:
cout<<"Please enter the product name\n";
	cin>>name_pro;
	for(int i=0;i<=ctr_product;i++){
		if(name_pro==Product[i][name]){
			flag=0;
	cout<<"Press [1] to update a code of product\nPress [2] to update a name of product\nPress [3] to update a price of product\nPress [4] to update a quantity of product\nPress [5] to update all\n";
	cout<<"your choice:";
	cin>>a;
	switch(a){//switch num2
		
	case 1:
	cout<<"Enter a new code for a product \n";
	cin>>Product[i][code];
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	cout<<"Type a new name for a prodect \n";
	cin>>Product[i][name];
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	cout<<"Enter a new price for a prodect \n";
	cin>>Product[i][price];
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	cout<<"Enter a new quantity for a products \n";
	cin>>Product[i][quantity];
	cout<<"\n*DONE*\n";
	break;
	
	case 5:
	cout<<"Enter a new code for a product \n";
	cin>>Product[i][code];
	cout<<"Type a new name for a prodect \n";
	cin>>Product[i][name];
	cout<<"Enter a new price for a prodect \n";
	cin>>Product[i][price];
	cout<<"Enter a new quantity for a products \n";
	cin>>Product[i][quantity];	

	cout<<"\n*DONE*\n";
	break;
	default:
		
		cout<<"invalid!\n"<<endl;
		break;

	}	//end switch 	
}//end if
}//end for
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;

case 3:
cout<<"Please enter the product price\n";
	cin>>pric;
	for(int i=0;i<=ctr_product;i++){
		if(pric==Product[i][price]){
			flag=0;
	cout<<"Press [1] to update a code of product\nPress [2] to update a name of product\nPress [3] to update a price of product\nPress [4] to update a quantity of product\nPress [5] to update all\nYour choice :";
	cin>>a;
	switch(a){//switch 
		
	case 1:
	cout<<"Enter a new code for a product \n";
	cin>>Product[i][code];
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	cout<<"Type a new name for a prodect \n";
	cin>>Product[i][name];
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	cout<<"Enter a new price for a prodect \n";
	cin>>Product[i][price];
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	cout<<"Enter a new quantity for a products \n";
	cin>>Product[i][quantity];
	cout<<"\n*DONE*\n";
	break;
	
	case 5:
	cout<<"Enter a new code for a product \n";
	cin>>Product[i][code];
	cout<<"Type a new name for a prodect \n";
	cin>>Product[i][name];
	cout<<"Enter a new price for a prodect \n";
	cin>>Product[i][price];
	cout<<"Enter a new quantity for a products \n";
	cin>>Product[i][quantity];	

	cout<<"\n*DONE*\n";
	break;
	default:
		
		cout<<"invalid!\n"<<endl;
		break;

	}//end switch 		
		
}//end if
}//end for
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;

case 4 :
		cout<<"Please enter the product quantity\n";
	cin>>quantit;
	for(int i=0;i<=ctr_product;i++){
		if(quantit==Product[i][quantity]){
			flag=0;
	cout<<"Press [1] to update a code of product\nPress [2] to update a name of product\nPress [3] to update a price of product\nPress [4] to update a quantity of product\nPress [5] to update all\nYour choice :";
	cin>>a;
	switch(a){//switch 
			
	case 1:
	cout<<"Enter a new code for a product \n";
	cin>>Product[i][code];
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	cout<<"Type a new name for a prodect \n";
	cin>>Product[i][name];
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	cout<<"Enter a new price for a prodect \n";
	cin>>Product[i][price];
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	cout<<"Enter a new quantity for a products \n";
	cin>>Product[i][quantity];
	cout<<"\n*DONE*\n";
	break;
	
	case 5:
	cout<<"Enter a new code for a product \n";
	cin>>Product[i][code];
	cout<<"Type a new name for a prodect \n";
	cin>>Product[i][name];
	cout<<"Enter a new price for a prodect \n";
	cin>>Product[i][price];
	cout<<"Enter a new quantity for a products \n";
	cin>>Product[i][quantity];	

	cout<<"\n*DONE*\n";
	break;
	default:
	
		cout<<"invalid!\n"<<endl;
		break;

	}//end switch 
}//end if
}//end for
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;
	default: 
	cout<<"Invalid!\n"<<endl; 
	break;}//end switch outer
}//end else
break;}



case 2:
{
   
if(ctr_location==0){
	 	
	 cout<<"\n Sorry there is no location to update it!\n";
	 system("pause");
	system("cls");	
	
	 }
	 else{
	 	cout<<"chooes the way to find the desired location :\n[1]location number\n[2]section name\n[3]aisle\n[4]shelf\n";
	cout<<"your choice:";
	 	cin>>b;
	 	switch(b){//outer switch
	 		case 1:
	 		cout<<"Please enter the number of location\n ";
		cin>>num_L;
		
		for(int j=0;j<=ctr_location;j++){
			if(num_L==location[j][loca]){
				
	flag=0;
	cout<<"Press [1] to update a number of location\nPress [2] to update a section name of location\nPress [3] to update  a aisle number of location\nPress [4] to update a shelf number of location\nPress [5] to update all\nYour choice: ";
	cin>>a;
	switch(a){
		case 1:
	cout<<"Enter a new location number\n";
	cin>>location[j][loca];
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	cout<<"Type a new section name\n";
	cin>>location[j][sec];
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	cout<<"Enter a shelf number for a location\n";
	cin>>location[j][shelf];
	cout<<"\n*DONE*\n";
	break;
	
	case 3:		
	cout<<"Enter a aisle number for a location\n";
	cin>>location[j][ais];
	cout<<"\n*DONE*\n";
	case 5:
	cout<<"Enter a new location number\n";
	cin>>location[j][loca];
	cout<<"Type a new section name\n";
	cin>>location[j][sec];
	cout<<"Enter a aisle number for a location\n";
	cin>>location[j][ais];
	cout<<"Enter a shelf number for a location\n";
	cin>>location[j][shelf];
	cout<<"\n*DONE*\n";
	break;
	default:
		
		cout<<"invalid!\n"<<endl;
		break;
	 		
	 }//switch
}//if
}//for

if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;

case 2:
	
		cout<<"Please enter the section name of location\n ";
		cin>>name_lo;
		
		for(int j=0;j<=ctr_location;j++){
			
if(name_lo==location[j][sec]){
	flag=0;
cout<<"Press [1] to update a number of location\nPress [2] to update a section name of location\nPress [3] to update  a aisle number of location\nPress [4] to update a shelf number of location\nPress [5] to update all\nYour choice: ";
	cin>>a;
	switch(a){
	case 1:
	cout<<"Enter a new location number\n";
	cin>>location[j][loca];
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	cout<<"Type a new section name\n";
	cin>>location[j][sec];
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	cout<<"Enter a shelf number for a location\n";
	cin>>location[j][shelf];
	cout<<"\n*DONE*\n";
	break;
	
	case 3:		
	cout<<"Enter a aisle number for a location\n";
	cin>>location[j][ais];
	cout<<"\n*DONE*\n";
	break;
	case 5:
	cout<<"Enter a new location number\n";
	cin>>location[j][loca];
	cout<<"Type a new section name\n";
	cin>>location[j][sec];
	cout<<"Enter a aisle number for a location\n";
	cin>>location[j][ais];
	cout<<"Enter a shelf number for a location\n";
	cin>>location[j][shelf];
	cout<<"\n*DONE*\n";
	break;
	default:
		
		cout<<"invalid!\n"<<endl;
		break;
}//s
}//if
}//for

if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;

case 3:
	cout<<"Please enter the aisle number of location\n ";
		cin>>ai;
		
		for(int j=0;j<=ctr_location;j++){
			if(ai==location[j][ais]){
	flag=0;
	cout<<"Press [1] to update a number of location\nPress [2] to update a section name of location\nPress [3] to update  a aisle number of location\nPress [4] to update a shelf number of location\nPress [5] to update all\nYour choice: ";
	cin>>a;
	switch(a){
		case 1:
	cout<<"Enter a new location number\n";
	cin>>location[j][loca];
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	cout<<"Type a new section name\n";
	cin>>location[j][sec];
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	cout<<"Enter a shelf number for a location\n";
	cin>>location[j][shelf];
	cout<<"\n*DONE*\n";
	break;
	
	case 3:		
	cout<<"Enter a aisle number for a location\n";
	cin>>location[j][ais];
	cout<<"\n*DONE*\n";
	
	break;
	case 5:
	cout<<"Enter a new location number\n";
	cin>>location[j][loca];
	cout<<"Type a new section name\n";
	cin>>location[j][sec];
	cout<<"Enter a aisle number for a location\n";
	cin>>location[j][ais];
	cout<<"Enter a shelf number for a location\n";
	cin>>location[j][shelf];
	cout<<"\n*DONE*\n";
	break;
	default:
			
		cout<<"invalid!\n"<<endl;
		break;
}//s
}//if
}//for

if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;

case 4:
		cout<<"Please enter the shelf number of location\n ";
		cin>>shel;
		
		for(int j=0;j<=ctr_location;j++){
			if(shel==location[j][shelf]){

	flag=0;
	cout<<"Press [1] to update a number of location\nPress [2] to update a section name of location\nPress [3] to update  a aisle number of location\nPress [4] to update a shelf number of location\nPress [5] to update all\nYour choice: ";
	cin>>a;
	switch(a){
			case 1:
	cout<<"Enter a new location number\n";
	cin>>location[j][loca];
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	cout<<"Type a new section name\n";
	cin>>location[j][sec];
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	cout<<"Enter a shelf number for a location\n";
	cin>>location[j][shelf];
	cout<<"\n*DONE*\n";
	break;
	
	case 3:		
	cout<<"Enter a aisle number for a location\n";
	cin>>location[j][ais];
	cout<<"\n*DONE*\n";
	break;
	case 5:
	cout<<"Enter a new location number\n";
	cin>>location[j][loca];
	cout<<"Type a new section name\n";
	cin>>location[j][sec];
	cout<<"Enter a aisle number for a location\n";
	cin>>location[j][ais];
	cout<<"Enter a shelf number for a location\n";
	cin>>location[j][shelf];
	cout<<"\n*DONE*\n";
	break;
	default:
			
		cout<<"invalid!\n"<<endl;
		break;
	}//s
}//if
}//for

if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;

default:
	cout<<"Invalid!\n"<<endl;
	
}//end switch outer
	 			
	 }//end else
}
break;
default:
cout<<"invalid!\n"<<endl;
break;
}
	system("pause");
	system("cls");
}//-----------------------------------------------------------------end function

//___________________________________________________________________________________________________________________________________________________________

//this function allow the user to remove singlge information from product/location records

void Remove(){
cout<<"=====================\n REMOVING DETAILS \n====================\n";
	cout<<endl;	
	
	int s,a,b,x,p,flag=1,d;
	string code_num,name_pro,pric,quantit,num_L,name_lo,shel,ai;
	cout<<"...Enter [1] to remove details of product [2]... to remove details of location...\n";
	cin>>d;
	switch(d){
		case 1:{
	
	if(ctr_product==0){
	 	
	 cout<<"\n Sorry there is no product to remove!\n";
	 system("pause");
	system("cls");	
		
	 }
	 else{
	cout<<"chooes the way to find the desired product :\n[1]code\n[2]name\n[3]price\n[4]quantity\n";
	cout<<"your choice:";
	cin>>b;
	switch(b){
		case 1:
	cout<<"Enter the product code\n";
	cin>>code_num;
	for(int i=0;i<=ctr_product;i++){
		if(code_num==Product[i][code]){
			flag=0;
	cout<<"press [1] to remove a code of product\npress [2] to remove a name of product\npress [3] to remove a price of product\npress [4] to remove a quantity of product\n";
	cin>>a;
	switch(a){
		case 1:
	Product[i][code]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	Product[i][name]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	Product[i][price]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	Product[i][quantity]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	default:
		cout<<"\ninvalid!\n"<<endl;
		break;

}//end s
}//if
}//for
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;		
	}
break;	
case 2:
		cout<<"Enter the product name\n";
	cin>>name_pro;
	for(int i=0;i<=ctr_product;i++){
		if(name_pro==Product[i][name]){
			flag=0;
	cout<<"press [1] to remove a code of product\npress [2] to remove a name of product\npress [3] to remove a price of product\npress [4] to remove a quantity of product\n";
	cin>>s;
	switch(s){
		case 1:
	Product[i][code]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 2:
	Product[i][name]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	Product[i][price]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	Product[i][quantity]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	default:
		cout<<"\ninvalid!\n"<<endl;
		break;

	}//end s
}//end if
	
}//end for
	if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;		
	}
break;
case 3:

cout<<"Enter the product price\n";
	cin>>pric;
	for(int i=0;i<=ctr_product;i++){
		if(pric==Product[i][price]){
			flag=0;
	cout<<"press [1] to remove a code of product\npress [2] to remove a name of product\npress [3] to remove a price of product\npress [4] to remove a quantity of product\n";
	cin>>x;
	switch(x){
		case 1:
	Product[i][code]=" ";
		cout<<"\n*DONE*\n";
	break;
	
	case 2:
	Product[i][name]=" ";
		cout<<"\n*DONE*\n";
	break;
	
	case 3:
	Product[i][price]=" ";
		cout<<"\n*DONE*\n";
	break;
	
	case 4:
	Product[i][quantity]=" ";
		cout<<"\n*DONE*\n";
	break;
	
	default:
		cout<<"\ninvalid!\n"<<endl;
		break;

	}//end s

}//endif
}//end for
	if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
}

break;
case 4:
	cout<<"Enter the product quantity\n";
	cin>>quantit;
	for(int i=0;i<=ctr_product;i++){
		if(quantit==Product[i][quantity]){
			flag=0;
	cout<<"press [1] to remove a code of product\npress [2] to remove a name of product\npress [3] to remove a price of product\npress [4] to remove a quantity of product\n";
	cin>>p;
	switch(p){
		case 1:
	Product[i][code]=" ";
		cout<<"\n*DONE*\n";
	break;
	
	case 2:
	Product[i][name]=" ";
		cout<<"\n*DONE*\n";
	break;
	
	case 3:
	Product[i][price]=" ";
		cout<<"\n*DONE*\n";
	break;
	
	case 4:
	Product[i][quantity]=" ";
		cout<<"\n*DONE*\n";
	break;
	
	default:
		cout<<"\ninvalid!\n"<<endl;
		break;

	}//end switch
}//end if
}//end for
	if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
}
break;

default:
cout<<"\ninvalid\n";	
}//end outer switch
}//end else
break;
}

case 2:
{

	if(ctr_location==0){
	 	
	 cout<<"\n Sorry there is no location to remove!\n";
	 system("pause");
	system("cls");	
	
	 }
	 else{
	cout<<"chooes the way to find the desired location :\n[1]location number\n[2]section name\n[3]aisle\n[4]shelf\n";
	cout<<"your choice:";
	cin>>b;
	 	
	switch(b){
	 		
	case 1:
	 			
	cout<<"Enter the location number \n";
	cin>>num_L;
	for(int j=0;j<=ctr_location;j++){
		if(num_L==location[j][loca]){
			flag=0;
	cout<<"Press [1] to remove a number of location\nPress [2] to remove a section name of location\nPress [3] to remove a aisle number of location\nPress [4] to remove a shelf number of location\n";
	cout<<"Your choice";
	cin>>a;
	switch(a){
		case 1:
	location[j][loca]=" ";
	cout<<"\n*DONE*\n";
	break;
		
		case 2:
	location[j][sec]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	location[j][ais]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	location[j][shelf]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	default:
		cout<<"invalid!\n"<<endl;
		break;
	}//end s
}//if
}//for
	if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
}
break;

case 2:
	cout<<"Please enter the name of location\n ";
		cin>>name_lo;
	for(int j=0;j<=ctr_location;j++){
		if(name_lo==location[j][sec]){
			flag=0;
		cout<<"Press [1] to remove a number of location\nPress [2] to remove a section name of location\nPress [3] to remove a aisle number of location\nPress [4] to remove a shelf number of location\n";
	cout<<"Your choice";
	cin>>a;
	
	switch(a){
			case 1:
	location[j][loca]=" ";
	cout<<"\n*DONE*\n";
	break;
		
		case 2:
	location[j][sec]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	location[j][ais]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	location[j][shelf]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	default:
		cout<<"invalid!\n"<<endl;
		break;
	}//s
}//if
	
}//end for
	 		
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;
	
case 3:
	cout<<"Please enter the aisle number of location\n ";
		cin>>ai;
	for(int j=0;j<=ctr_location;j++){
		if(ai==location[j][ais]){
			flag=0;
	cout<<"Press [1] to remove a number of location\nPress [2] to remove a section name of location\nPress [3] to remove a aisle number of location\nPress [4] to remove a shelf number of location\n";
	cout<<"Your choice";
	cin>>a;
	switch(a){
		location[j][loca]=" ";
	cout<<"\n*DONE*\n";
	break;
		
		case 2:
	location[j][sec]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	location[j][ais]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	location[j][shelf]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	default:
		cout<<"invalid!\n"<<endl;
		break;
	}//s
}//if
}//end for	 		
	 		
	 
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;}
break;		

 case 4:
 cout<<"Pease enter the shelf number of location\n ";
		cin>>shel;
		
		for(int j=0;j<=ctr_location;j++){
			if(shel==location[j][shelf]){
			flag=0;
	cout<<"Press [1] to remove a number of location\nPress [2] to remove a section name of location\nPress [3] to remove a aisle number of location\nPress [4] to remove a shelf number of location\n";
	cout<<"Your choice";
	cin>>a;
	switch(a){
			location[j][loca]=" ";
	cout<<"\n*DONE*\n";
	break;
		
		case 2:
	location[j][sec]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 3:
	location[j][ais]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	case 4:
	location[j][shelf]=" ";
	cout<<"\n*DONE*\n";
	break;
	
	default:
		cout<<"invalid!\n"<<endl;
		break;

	}//s
}//if
}//end for	 		
	 			 
if(flag==1){
cout<<"=================\n"	;	
cout<<"can not found!\n";		
cout<<"=================\n"	;
}
break;				 

default:
cout<<"\ninvalid\n";		 
break;
}//end outer switch
}//end else
break;
}
default:
cout<<"invalid!\n"<<endl;
break;}
system("pause");
	system("cls");
}//-------------------------------------------------------------end fancation
