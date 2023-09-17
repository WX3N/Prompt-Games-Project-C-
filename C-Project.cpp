#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct user{
	char nama[21];
	char pass[21];
	int floor;
	int hp;
	int currhp;
	int atk;
	int luck;
	int pothp;
	int potshp;
	int coin;
	int statpoint;
	char monster[20];
};

void signup();
void login();
void createchar(user data);
void gamemenu(user data);
void update(user data);
int random(user data);
void potshop(user data);
void status(user data);
void monster(user data);
void battle(user data, int hp, int atk);
void end(user data);

int main(){
	system("cls");
	int jwb;
	do{
		printf("Tutorial Tower\n");
		printf("1. Sign-Up\n");
		printf("2. Login\n");
		scanf("%d",&jwb);
		getchar();
		system("cls");
	}while(jwb<1||jwb>2);
	
	if(jwb == 1){
		signup();
	}
	else if(jwb == 2){
		login();
	}

		
	return 0;
}

void signup(){
	printf("Enter 0 to back\n");
	user data;
	do{
		printf("Username [3-20 character] : ");
		scanf("%[^\n]",data.nama);
		getchar();
		
		if(!strcmp("0",data.nama)){
			main();
		}
			
		for(int i=0; i<strlen(data.nama); i++){
			if(data.nama[i]==' '){
				strcpy(data.nama,"0");
				printf("Don't use ' ' in your username!\n");
				break;
			}				
		}
	}while(strlen(data.nama)<3||strlen(data.nama)>20);
	
	char temp_nama[21];
	char temp_pass[21];
	
	FILE *fp;
	fp=fopen("account.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%s %s\n",temp_nama,temp_pass);
		if(!strcmpi(temp_nama,data.nama)){
			system("cls");
			printf("Username already exist\n");
			printf("Please input another one\n\n");	
			signup();
		}
	}	
	fclose(fp);

	do{
		printf("Password [3-20 character] : ");
		scanf("%[^\n]",data.pass);
		getchar();
		
		if(!strcmp("0",data.pass)){
			main();
		}
		
		if(!strcmpi(data.pass , data.nama)){
			strcpy(data.pass,"0");
			printf("\nUsername and password MUST be diffrent!\n");
			printf("Please input another password\n\n");
		}
	}while((strlen(data.pass)<3||strlen(data.pass)>20));

	fp=fopen("account.txt","a");
	fprintf(fp,"%s %s\n",data.nama , data.pass);
	fclose(fp);

	main();
}

void login(){
	printf("Enter 0 to back\n");
	user data;
	char nama[21];
	char pass[21];
	
	printf("Username [3-20 character] : ");
	scanf("%[^\n]",nama);
	getchar();
	
	if(!strcmp("0",nama)){
		main();	
	}
		
	printf("Password [3-20 character] : ");
	scanf("%[^\n]",pass);
	getchar();
	
	if(!strcmp("0",pass)){
		main();	
	}
	
	int status=0;
	
	FILE *fp;
	fp=fopen("account.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%s %s\n", data.nama, data.pass);
		if(!strcmp(nama, data.nama)){
			if(!strcmp(pass, data.pass)){
				status = 1;
				break;
			}
			else{
				status = 0;
				break;
			}				
		}
	}
	fclose(fp);
	
	if(status==1){
		fp=fopen(nama,"r");
		if(fp==NULL){
			fclose(fp);
			createchar(data);
		}
		else{
			fscanf(fp,"%d\n",&data.hp);
			fscanf(fp,"%d\n",&data.currhp);
			fscanf(fp,"%d\n",&data.atk);
			fscanf(fp,"%d\n",&data.luck);
			fscanf(fp,"%d\n",&data.pothp);
			fscanf(fp,"%d\n",&data.potshp);
			fscanf(fp,"%d\n",&data.coin);
			fscanf(fp,"%d\n",&data.floor);
			fclose(fp);
			gamemenu(data);	
		}	
	}
	else{
		printf("Username/password is wrong!\n");
		printf("Please enter the corect one\n\n");
		printf("Press enter to continue to back to main menu...\n");
		getchar();
		main();
	}
}

void createchar(user data){
	printf("===============================================\n");
	printf("|     Congratulation to awaken as hunter      |\n");
	printf("===============================================\n");
	printf("|            Please check your stat           |\n");
	printf("|=============================================|\n");
	printf("|                   Hp : 100                  |\n");
	printf("|                  Atk : 20                   |\n");
	printf("|                 Luck : 10                   |\n");
	printf("===============================================\n");
	printf("|---------------------------------------------|\n");
	printf("===============================================\n");
	printf("|               Hp : decided your hp          |\n");
	printf("|      Atk : decided your attack damage       |\n");
	printf("|Luck : decided your critical and dodge chance|\n");
	printf("===============================================\n");
	printf("|---------------------------------------------|\n");
	printf("===============================================\n");
	printf("|             Your stat point : 0             |\n");
	printf("|You can use stat point to increase your stat |\n");
	printf("===============================================\n");
	printf("Press enter to continue...\n");
	getchar();

	data.hp = 100;
	data.currhp = 100;
	data.atk = 20;
	data.luck = 10;
	data.floor = 1;
	data.potshp = 0;
	data.pothp = 5;
	data.coin = 5000;
	data.statpoint = 0;
	
	update(data);
	
	system("cls");
	int jwbn;
	
	printf("You can enter Tutorial Tower, do you want to enter?\n");
	printf("1. Yes\n");
	printf("2. No\n");
	scanf("%d",&jwbn);
	getchar();
	if(jwbn==1){
		printf("Transfering Hunter %s\n", data.nama);
		printf("System Error...\n\n");
		printf("Press enter to continue...\n");
		getchar();
	}
	else if(jwbn==2){
		printf("System reject your answer, automatically transfer hunter\n\n");
		printf("Press enter to continue...\n");
		getchar();
	}
	else{
		printf("Invalid Answer!\n");
		printf("System will do random choose\n");
		printf("System Error...\n\n");
		printf("Press enter to continue...\n");
		getchar();
	}
	system("cls");
	printf("====================================\n");
	printf("|     Welcome to Tutorial Tower    |\n");
	printf("====================================\n");
	printf("|    Mission : Reach floor 100	   |\n");
	printf("|     Reward : Back to earth       |\n");
	printf("====================================\n\n");
	printf("Press enter to continue...\n");
	getchar();
	gamemenu(data);
}

void gamemenu(user data){
	int jwb;
	do{
		system("cls");
		printf("====MENU====\n");
		printf("------------\n");
		printf("1. Enter floor %d\n",data.floor);
		printf("2. Potion Shop\n");
		printf("3. Stat\n");
		printf("4. Log out\n");
		scanf("%d",&jwb);
		getchar();
	}while(jwb<1 || jwb>4);
	
	if(jwb == 1){
		monster(data);
	}
	else if(jwb == 2){
		potshop(data);
	}
	else if(jwb == 3){
		status(data);
	}
	else if(jwb == 4){
		main();
	}
}

void potshop(user data){
	int jwb, pot;
	do{
		system("cls");
		printf("Coin : %d\n",data.coin);
		printf("Your potion :\n");
		printf("Health potion : %d\n",data.pothp);
		printf("Super Health potion : %d\n",data.potshp);
		printf("--------------\n");
		printf("Potion Shop\n");
		printf("===========\n");
		printf("1. Health Potion - 2000 coin\n");
		printf("2. Super Health Potion - 3000 coin\n");
		printf("3. Back\n");
		printf("------------\n");
		scanf("%d",&jwb);
		getchar();
	}while(jwb < 1 || jwb > 3);
	
	
	if(jwb == 1){
		system("cls");
		printf("Coin : %d\n",data.coin);
		printf("Number of Health Potion : ");
		scanf("%d",&pot);
		getchar();
		if(data.coin < pot*2000){
			printf("\nYou don't have enough coins\n");
			printf("Press enter to back\n");
			getchar();
			potshop(data);
		}
		do{
			system("cls");
			printf("Are you sure want to buy %d Health Potion?\n",pot);
			printf("1. Yes\n");
			printf("2. No\n");
			scanf("%d",&jwb);
			getchar();
		}while(jwb < 1 || jwb > 2);
			
		if(jwb == 1){
			data.coin = data.coin - (pot*2000);
			printf("You successfully purchase %d Health Potion\n",pot);
			printf("Press enter to continue...\n");
			getchar();
			data.pothp += pot;
			update(data);
			gamemenu(data);
		}
		else if(jwb == 2){
			potshop(data);	
		}			
	}

	else if(jwb == 2){
		system("cls");
		printf("Coin : %d\n",data.coin);
		printf("Number of Super Health Potion : ");
		scanf("%d",&pot);
		getchar();
		if(data.coin < pot*3000){
			printf("\nYou don't have enough coins\n");
			printf("Press enter to back\n");
			getchar();
			potshop(data);
		}
		do{
			system("cls");
			printf("Are you sure want to buy %d Super Health Potion?\n",pot);
			printf("1. Yes\n");
			printf("2. No\n");
			scanf("%d",&jwb);
			getchar();
		}while(jwb < 1 || jwb > 2);
				
		if(jwb == 1){
			data.coin = data.coin - (pot*3000);
			printf("You successfully purchase %d Super Health Potion\n",pot);
			printf("Press enter to continue...\n");
			getchar();
			data.potshp += pot;
			update(data); 
			gamemenu(data);
		}
		else if(jwb == 2){
			potshop(data);
		}			
		
	}
	else if(jwb == 3){
		gamemenu(data);
	}
	
}

void status(user data){
	system("cls");
	printf("----------------------\n");
	printf("Your Stat :\n");
	printf("Hp : %d / %d\n",data.currhp, data.hp);
	printf("Atk : %d\n",data.atk);
	printf("Luck : %d\n",data.luck);
	printf("Floor : %d\n",data.floor);
	printf("----------------------\n");
	printf("Coin : %d\n", data.coin);
	printf("----------------------\n");	
	printf("Potion :\n");
	printf("Health Potion : %d\n",data.pothp);
	printf("Super Health Potion : %d\n",data.potshp);
	printf("----------------------\n");
	printf("Press enter to back\n");
	getchar();
	gamemenu(data);
}

void monster(user data){
	system("cls");
	if(data.floor % 5 == 0){
		printf("Current stat : \n");
		printf("Hp : %d\n",data.hp);
		printf("Atk : %d\n",data.atk);
		printf("Luck : %d\n",data.luck);
		printf("+---------------------+\n");
		printf("Your stat point : %d\n",data.statpoint);
		printf("+-------------------------------+\n");
		printf("Convert point info :\n");
		printf("1 stat point = 20 hp\n");
		printf("1 stat point = 5 atk\n");
		printf("1 stat point = 5 luck\n\n");
		printf("+-------------------------------+\n");
		printf("Please distibute your stat point\n");
		int a,b,c;
		int point = data.statpoint;
		do{
			printf("HP : ");
			scanf("%d",&a);
			getchar();
		}while(a>point);
		point -= a;
		do{
			printf("Atk : ");
			scanf("%d",&b);
			getchar();
		}while(b>point);
		point -= b;
		do{
			printf("Luck : ");
			scanf("%d",&c);
			getchar();
		}while(c>point);
		point -= c;
		
		system("cls");
		printf("Are you sure want to distribute :\n");
		printf("%d point to Hp\n",a);
		printf("%d point to Atk\n",b);
		printf("%d point to Luck\n",c);
		printf("------------------\n");
		printf("1. Yes\n");
		printf("2. No\n");
		int j2;
		do{
			scanf("%d",&j2);
			getchar();
			if(j2<1 || j2>2)
				printf("Invalid answer!\n");
		}while(j2<1 && j2>2);
		
		system("cls");
		
		if(j2 == 1){
			
			if(data.statpoint - a - b - c != 0){
				do{
					system("cls");
					printf("You still have stat point!\n");
					printf("You can not up your stat until clear next 5 floor\n");
					printf("Are you sure want to continue?\n");
					printf("1. Yes\n");
					printf("2. No\n");
					scanf("%d",&j2);
					getchar();		
				}while(j2<1 || j2>2);
				
				if(j2 == 2)
					monster(data);
				
			}
			data.hp = data.hp + (a*30);
			data.atk = data.atk + (b*5);
			data.luck = data.luck + (c*5);
			
			data.statpoint = data.statpoint - a - b - c;
			printf("Current stat : \n");
			printf("Hp : %d\n",data.hp);
			printf("Atk : %d\n",data.atk);
			printf("Luck : %d\n",data.luck);
			printf("+---------------------+\n");
			printf("Stat point :%d\n",data.statpoint);
			update(data);
		}
		else
			monster(data);
	}
	
	int hp, atk;
	
	if(data.floor<=10){ 
		hp = 50+(data.floor*10); //60 - 150
		atk = 3+(data.floor*2);  //5 - 23
		strcpy(data.monster,"Slime");
	}
	else if(data.floor>10 && data.floor<=20){
		hp = 40+(data.floor*10); // 150 - 240
		atk = (data.floor*2); // 22 - 40
		strcpy(data.monster,"Goblin");
	}
	else if(data.floor>20 && data.floor<=30){ 
		hp = (data.floor*10); // 210 - 290
		atk = (data.floor*2)-5; // 37 - 55
		strcpy(data.monster,"Wolf");
	}
	else if(data.floor>30 && data.floor<=40){ 
		hp = (data.floor*10); // 310 - 400
		atk = (data.floor)-5; // 26 - 35
		strcpy(data.monster,"Orc");
	}
	else if(data.floor>40 && data.floor<=50){ 
		hp = (data.floor*7); // 287 - 350
		atk = (data.floor*2)-30; // 51 - 70
		strcpy(data.monster,"Lizardman");
	}
	else if(data.floor>50 && data.floor<=60){
		hp = (data.floor*6); // 306 - 360
		atk = (data.floor*2)-30; // 62 - 90
		strcpy(data.monster,"Witch");
	}
	else if(data.floor>60 && data.floor<=70){ 
		hp = (data.floor*5); //610 - 700
		atk = (data.floor)-10; //51 - 60
		strcpy(data.monster,"Druid");
	}
	else if(data.floor>70 && data.floor<=80){ 
		hp = (data.floor*6); // 426 - 480
		atk = (data.floor)+15; // 75 - 85
		strcpy(data.monster,"Wyvern");
	}
	else if(data.floor>80 && data.floor<=90){ 
		hp = (data.floor*10); //810 - 900
		atk = (data.floor)+10; //91 - 100
		strcpy(data.monster,"Golem");
	}
	else if(data.floor>90 && data.floor<100){ 
		hp = (data.floor*11); // 1001 - 1100
		atk = (data.floor*2); // 180 - 200
		strcpy(data.monster,"Dragon");
	}
	else if(data.floor == 100){ 
		hp = 2000; 
		atk = 200; 
		strcpy(data.monster,"King Of Tutorial Tower");
	}
	else if(data.floor > 100){
		end(data);
	}
	battle(data,hp, atk);
}

void battle(user data, int hp, int atk){
	system("cls");
	int jwb, crit, dodge;
	printf("------------------------------\n");
	printf("Floor : %d\n",data.floor);
	printf("%s\n",data.monster);
	printf("Hp   : %d\n",hp);
	printf("Atk  : %d\n",atk);
	printf("------------------------------\n");
	printf("Your stat :\n");
	printf("Hp   : %d / %d\n",data.currhp, data.hp);
	printf("Atk  : %d\n",data.atk);
	printf("Luck : %d\n",data.luck);
	printf("------------------------------\n");
	printf("1. Attack\n");
	printf("2. Health Potion (%d)\n",data.pothp);
	printf("3. Super Health Potion (%d)\n",data.potshp);
	printf("4. Flee\n");
	printf("------------------------------\n");	
	scanf("%d",&jwb);
	getchar();
		
	if(jwb<1 && jwb>4)
		battle(data, hp, atk);
	
	if(jwb == 1){
		
		crit = random(data);
		if(crit == 1){
			printf("You dealt critical damage\n");
			printf("Press enter to continue\n");
			getchar();
			hp -= (data.atk*2);
		}
		else
			hp -= data.atk;
		
		if(hp <= 0){
			system("cls");
			int coin = (rand() % (700 - 100 + 1)) + 100;
			coin = coin + (data.floor*10);
			data.coin += coin;
			printf("==========================\n");
			printf("Your stat :\n");
			printf("Hp   : %d / %d\n",data.currhp, data.hp);
			printf("Atk  : %d\n",data.atk);
			printf("Luck : %d\n",data.luck);
			data.floor++;
			printf("==========================\n");
			printf("Monster has been defeat...\n");
			printf("==========================\n");
			printf("Reward : %d coins\n",coin);
			printf("==========================\n");
			printf("Current coin : %d\n",data.coin);
			printf("==========================\n");
			if((data.floor) % 10 == 0){
				data.statpoint += 3;	
			}
			else if((data.floor) % 5 == 0 ){
				data.statpoint += 2;
			}
			update(data);
			int jwb2;
			
			if(data.floor == 101){
				end(data);
			}
			do{
				printf("Continue next floor?\n");
				printf("1. Yes\n");
				printf("2. No\n");
				scanf("%d",&jwb2);
			}while(jwb2<1 && jwb2>2);
			
			if(jwb2 == 1)
				monster(data);
			else
				gamemenu(data);		
		}
		
		dodge = random(data);
		if(dodge == 1){
			printf("You successfully dodge monster attack\n");	
			printf("Press enter to continue\n");
			getchar();
		}
				
		else
			data.currhp -= atk;
		
		if(data.currhp <= 0){
			printf("Fail to defeat monster\n");
			data.currhp = 1;
			update(data);
			printf("Press enter to back to main menu\n");
			getchar();
			gamemenu(data);
		}
		
		battle(data, hp, atk);
	}
	else if(jwb == 2){
		if(data.pothp - 1 >=0){
			printf("Successfully using Health Potion\n");
			data.currhp += 100;
			data.pothp -= 1;
			if(data.currhp > data.hp){
				data.currhp = data.hp;
			}
			printf("Press enter to continue\n");
			getchar();
			battle(data, hp, atk);
		}
		else{
			printf("You don't have enough Health Potion!\n");
			printf("Press enter to continue\n");
			getchar();
			battle(data, hp, atk);
		}	
	}
	else if(jwb == 3){
		if(data.potshp - 1 >=0){
			printf("Successfully using Super Health Potion\n");
			data.currhp += 250;
			data.potshp -= 1;
			if(data.currhp > data.hp){
				data.currhp = data.hp;
			}
			printf("Press enter to continue\n");
			getchar();
			battle(data, hp, atk);
		}
		else{
			printf("You don't have enough Health Potion!\n");
			printf("Press enter to continue\n");
			getchar();
			battle(data, hp, atk);
		}	
	}
	else if(jwb == 4){
		gamemenu(data);
	}
}

void update(user data){
	FILE *fp;
	fp=fopen(data.nama,"w");

	fprintf(fp,"%d\n",data.hp);
	fprintf(fp,"%d\n",data.currhp);
	fprintf(fp,"%d\n",data.atk);
	fprintf(fp,"%d\n",data.luck);
	fprintf(fp,"%d\n",data.pothp);
	fprintf(fp,"%d\n",data.potshp);
	fprintf(fp,"%d\n",data.coin);
	fprintf(fp,"%d\n",data.floor);
	fprintf(fp,"%d\n",data.statpoint);
	fclose(fp);
}

int random(user data){
	int num = (rand()%100) + 1;
	srand(time(0));
	
	int status = 0;
	
	if(data.luck >= num){
		status = 1;
	}
	
	return status;
	
}

void end(user data){
	system("cls");
	printf("Congrats for completing 100 floors on the tutorial tower\n");
	printf("Transfering hunter %s back to earth",data.nama);
	printf("Your journey start now!\n");
	system("cls");
	printf("Thank You For Playing Tutorial Tower\n");
	printf("~ See U Next Time In Another Tower ~\n");
	getchar();
	gamemenu(data);
}