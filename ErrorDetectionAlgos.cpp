#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

vector<string> bitData = {
  "01000001",
  "01000010",
  "01000011",
  "01000100",
  "01000101",
  "01000110",
  "01000111",
  "01001000",
  "01001001",
  "01001010",
  "01001011",
  "01001100",
  "01001101",
  "01001110",
  "01001111",
  "01010000",
  "01010001",
  "01010010",
  "01010011",
  "01010100",
  "01010101",
  "01010110",
  "01010111",
  "01011000",
  "01011001",
  "01011010"
};

void printWelcome(){
     cout<<"\n\n";
     for(int i = 0; i < 210; i++) cout<<"#";
     cout<<"\n\n";
     cout<<setw(120)<<"ERROR DETECTION ALGORITHMS";
     cout<<"\n\n";
     for(int i = 0; i < 210; i++) cout<<"#";
     cout<<"\n";
}
void printSenderSide(){
     cout<<"\n\n";
     for(int i = 0; i < 110; i++) cout<<"-";
     cout<<"\n\n";
     cout<<setw(60)<<"SENDER SIDE";
     cout<<"\n\n";
     for(int i = 0; i < 110; i++) cout<<"-";
     cout<<"\n";
}
void printReceiverSide(){
     cout<<"\n\n";
     for(int i = 0; i < 110; i++) cout<<"-";
     cout<<"\n\n";
     cout<<setw(61)<<"RECEIVER SIDE";
     cout<<"\n\n";
     for(int i = 0; i < 110; i++) cout<<"-";
     cout<<"\n\n";
}
int convertToDecimal(string s){
     int power = 1;
     int ans = 0;

     for(int i = s.length()-1; i >= 0; i--){
          if(s[i] == '1')
               ans += power;
          power *= 2;
     }
     return ans;
}
string convertToBinary(int d){
     string ans = "";
     while(d){
          if(d % 2 == 1) ans += '1';
          else ans += '0';
          d /= 2;
     }
     reverse(ans.begin(),ans.end());
     return ans;
}


void singleParityCheck(){
     cout<<setw(69)<<"|* SINGLE PARITY CHECK *|\n\n";
     string data;
     string bit = "";
     cout<<"* Enter Data to be Transmitted: "; cin >> data;
     cout<<"* Data to be Transmitted: \n\n";

     for(int i = 0; i < 30; i++) cout<<"=";
     cout<<"\n";
     cout<<setw(10)<<"CHARACTER";
     cout<<setw(18)<<"BITDATA\n";
     for(int i = 0; i < 30; i++) cout<<"=";
     cout<<"\n";

     for(char &c: data){
          Sleep(75);
          c = toupper(c);
          bit += bitData[c-'A'];
          cout<<setw(5)<<c;
          cout<<setw(23)<<bitData[c - 'A'];
          cout<<"\n";
     }
     cout<<"\n\n";

     cout<<"* Bit Stream to be Transmitted: "; cout<<bit<<"\n";
     int oneCount = 0;
     for(char c:bit) if(c == '1') oneCount++;
     int parity = (oneCount % 2 == 0)? 0:1;
     cout<<"* Parity Bit on Sender Side:\t"<<parity<<"\n";
     bit += parity + '0';
     cout<<"* Data with Parity Bit:         "<<bit<<"\n\n";

     Sleep(50);
     cout<<"* Press Any Key to Inject Noise and Transmit";
     _getch();

     printReceiverSide();
     Sleep(75);
     int r = rand()%(bit.length()-1);
     if(bit[r] == '1') bit[r] = '0';
     else bit[r] = '1';

     cout<<"* Received Bit Stream: \t\t"<<bit<<"\n";
     oneCount = 0;
     for(int i=0;i<bit.length()-1;i++) if(bit[i] == '1') oneCount++;
     parity = (oneCount % 2 == 0)? 0:1;

     cout<<"* Parity Bit on Receiver Side:\t"<<parity<<"\n\n";
     Sleep(45);
     cout<<"* Sender Parity Bit is not equal to Receiver Parity Bit.\n";
     cout<<"* Data is rejected.\n";
}
void twoDParityCheck(){
     cout<<setw(67)<<"|* 2D PARITY CHECK *|\n\n";
     string data;
     string bit = "";
     cout<<"* Enter Data to be Transmitted: "; cin >> data;
     cout<<"* Data to be Transmitted: \n\n";

     for(int i = 0; i < 30; i++) cout<<"=";
     cout<<"\n";
     cout<<setw(10)<<"CHARACTER";
     cout<<setw(18)<<"BITDATA\n";
     for(int i = 0; i < 30; i++) cout<<"=";
     cout<<"\n";

     for(char &c: data){
          Sleep(75);
          c = toupper(c);
          bit += bitData[c-'A'];
          cout<<setw(5)<<c;
          cout<<setw(23)<<bitData[c - 'A'];
          cout<<"\n";
     }
     cout<<"\n\n";
     vector<int> rowParity(data.length()+1);
     vector<int> colParity(9,0);

     cout<<"* Bit Stream to be Transmitted: "; cout<<bit<<"\n\n";
     cout<<"* 2D Parity Check on Sender Side: \n";

     for(int i = 0;i < 38; i++) cout<<"-";
     cout<<'\n';
     for(int i = 0; i < data.length(); i++){
          data[i] = toupper(data[i]);
          int oneCount = 0;
          int parity = 0;
          string binaryCode = bitData[data[i]-'A'];
          for(int j = 0; j < binaryCode.length(); j++){
               Sleep(75);
               cout<<" "<<binaryCode[j]<<"  ";
               if(binaryCode[j] == '1'){
                    oneCount++;
                    colParity[j]++;
               }
          }
          if(oneCount % 2 == 1) parity = 1;
          cout<<"|  "<<parity<<"\n";
          rowParity[i] = parity;
          if(parity == 1) colParity[8]++;
     }
     for(int i = 0; i < 9; i++) colParity[i] = (colParity[i] % 2 == 0)? 0:1;
     for(int i = 0;i < 38; i++) cout<<"-";
     cout<<"\n ";
     for(int i = 0;i < 7; i++) cout<<colParity[i]<<"   ";
     cout<<colParity[7]<<"  ";
     cout<<"|  "<<colParity[8]<<"\n\n";

     Sleep(50);
     cout<<"* Press Any Key to Inject Noise and Transmit";
     _getch();
     printReceiverSide();
     Sleep(75);
     int errorCount = 3;
     while(errorCount){
          int r = rand() % (bit.length());
          if(bit[r] == '1') bit[r] = '0';
          else bit[r] = '1';
          errorCount--;
     }

     cout<<"* Received Bit Stream: \t\t"<<bit<<"\n";
     cout<<"* 2D Parity Check on Receiver Side: \n";
     vector<int> rec_rowParity(data.length()+1);
     vector<int> rec_colParity(9,0);

     for(int i = 0;i < 38; i++) cout<<"-";
     cout<<'\n';
     for(int i = 0; i < bit.length(); i+=8){
          int oneCount = 0;
          int parity = 0;
          for(int j = i; j < i+8; j++){
               Sleep(75);
               cout<<" "<<bit[j]<<"  ";
               if(bit[j] == '1'){
                    oneCount++;
                    rec_colParity[j]++;
               }
          }
          if(oneCount % 2 == 1) parity = 1;
          cout<<"|  "<<parity<<"\n";
          rec_rowParity[i] = parity;
          if(parity == 1) rec_colParity[8]++;
     }
     for(int i = 0; i < 9; i++) rec_colParity[i] = (rec_colParity[i] % 2 == 0)? 0:1;
     for(int i = 0;i < 38; i++) cout<<"-";
     cout<<"\n ";
     for(int i = 0;i < 7; i++) cout<<rec_colParity[i]<<"   ";
     cout<<rec_colParity[7]<<"  ";
     cout<<"|  "<<rec_colParity[8]<<"\n\n";

     cout<<"* Row Parities at Receiver Side do not match Row Parities at Sender Side.\n";
     cout<<"* Column Parities at Receiver Side do not match Column Parities at Sender Side.\n";
     cout<<"* Data is Rejected\n";
}

string checkSumHelper(vector<string> &blocks){
     int total = 0;
     cout<<"* Performing the summation of following blocks of bits: \n\n";
     for(string &s: blocks){
          cout<<"  ";
          for(char &c: s){
               cout<<c<<"   ";
          }
          total += convertToDecimal(s);
          cout<<"\n";
     }
     for(int i = 0; i < 32; i++) cout<<"-";
     cout<<"\n";
     cout<<"  ";
     string totalBin = convertToBinary(total);
     string carry = "";

     if(totalBin.length() > 8){
          while(totalBin.length() > 8){
               carry = totalBin.substr(0,totalBin.length()-8);
               totalBin = totalBin.substr(totalBin.length()-8);
               for(char &c : totalBin){
                    cout<<c<<"   ";
               }
               cout<<"  <-- Binary Addition";
               cout<<"\n";
               cout<<"  ";
               for(int i = 0; i < 8 - carry.length(); i++) cout<<"    ";
               for(char &c: carry){
                    cout<<c<<"   ";
               }
               cout<<"  <-- Carry\n";

               for(int i = 0; i < 32; i++) cout<<"-";
               cout<<"\n";
               total = convertToDecimal(totalBin) + convertToDecimal(carry);
               totalBin = convertToBinary(total);

               while(totalBin.length() < 8) totalBin = '0' + totalBin;
               cout<<"  ";
               for(char &c : totalBin){
                    cout<<c<<"   ";
               }
               cout<<"  <-- Binary Addition";
               cout<<"\n";
               for(int i = 0; i < 32; i++) cout<<"-";
               cout<<"\n";
          }
     }
     else{
          for(char &c : totalBin){
               cout<<c<<"   ";
          }
          cout<<"  <-- Binary Addition";
          cout<<"\n";
          for(int i = 0; i < 32; i++) cout<<"-";
          cout<<"\n";
     }

     cout<<"  ";

     string addOn = "";
     for(char &c: totalBin){
          if(c == '1'){
               addOn += '0';
               cout<<"0"<<"   ";
          }
          else{
               addOn += '1';
               cout<<"1"<<"   ";
          }
     }

     cout<<"  <-- 1's Complement\n";
     return addOn;
}
void checkSum(){
     cout<<setw(63)<<"|* CHECKSUM *|\n\n";
     string data;
     string bit = "";
     vector<string> blocks;
     cout<<"* Enter Data to be Transmitted: "; cin >> data;
     cout<<"\n\n";
     cout<<"* Data to be Transmitted: \n";

     for(int i = 0; i < 30; i++) cout<<"=";
     cout<<"\n";
     cout<<setw(10)<<"CHARACTER";
     cout<<setw(18)<<"BITDATA\n";
     for(int i = 0; i < 30; i++) cout<<"=";
     cout<<"\n";

     for(char &c: data){
          Sleep(75);
          c = toupper(c);
          bit += bitData[c-'A'];
          blocks.push_back(bitData[c-'A']);
          cout<<setw(5)<<c;
          cout<<setw(23)<<bitData[c - 'A'];
          cout<<"\n";
     }
     cout<<"\n";
     string addOn = checkSumHelper(blocks);
     bit += addOn;
     cout<<"\n\n* Bit Stream to be transmitted:\t"<<bit<<" (Bit Stream + 1's Complement)\n";
     cout<<"\nPress any key to inject noise and transmit.";
     _getch();


     int errorCount = 5;
     while(errorCount--){
          int r = rand() % (bit.length());
          if(bit[r] == '1') bit[r] == '0';
          else bit[r] = '1';
     }

     printReceiverSide();

     cout<<"* Bit Stream at Receiver Side: "<<bit<<"\n";

     blocks.clear();
     string currBlock = "";
     for(char &c : bit){
          currBlock += c;
          if(currBlock.length() == 8){
               blocks.push_back(currBlock);
               currBlock = "";
          }
     }
     string remainder = checkSumHelper(blocks);

     bool allzero = true;
     for(char &c:remainder) if(c == '1') allzero = false;

     if(!allzero){
          cout<<"\n\n* Remainder on the Receiver Side is not 0.\n";
          cout<<"* Data is rejected.\n";
     }
     else{
          cout<<"\n\n* Remainder is 0.\n";
          cout<<"* No error in transmission. Data is accepted.\n";
     }

}

string CRC_helper(string data, string divisor){

     for(int i = 0; i < divisor.length()+2;i++) cout<<" ";
     for(int i = 0; i < data.length()+2; i++) cout<<"_";
     cout<<"\n";
     cout<<divisor<<" | "<<data<<"\n";

     int gap = divisor.length()+3;

     string curr;
     string quotient = "";
     string remainder = "";

     for(int i = 0; i <= data.length(); i++){

        if(i < divisor.length()){
           curr += data[i];
           continue;
        }
        if(curr[0] == '0') quotient += '0';
        else quotient += '1';
        for(int x = 0; x < gap; x++) cout<<" ";
        if(quotient.back() == '1'){
           cout<<divisor<<"\n";
           if(i >= divisor.length()){
                for(int x = 0; x < gap; x++) cout<<" ";
                for(int x = 0; x < divisor.length(); x++) cout<<"-";
                cout<<"\n";
           }
           for(int j = 1; j < divisor.length(); j++){
              if(divisor[j] == '0' && curr[j] == '0' || divisor[j] == '1' && curr[j] == '1' ){
                 remainder += '0';
              }
              else remainder += '1';
           }
        }
        else{
           for(int x=0; x<divisor.length();x++) cout<<'0';
           cout<<"\n";
           if(i >= divisor.length()){
                for(int x = 0; x < gap; x++) cout<<" ";
                for(int x = 0; x < divisor.length(); x++) cout<<"-";
                cout<<'\n';
           }
           for(int j = 1; j < divisor.length(); j++){
              if(curr[j] == '0') remainder += '0';
              else remainder += '1';
           }
        }
        gap += 1;
        if(i != data.length()){
           remainder += data[i];
           curr = remainder;
           remainder = "";
           for(int x = 0; x < gap; x++) cout<<" ";
           for(int x = 0; x < divisor.length(); x++) cout<<curr[x];
           cout<<"\n";
        }
     }
     for(int x=0;x<gap;x++)cout<<" ";
     for(char c:remainder)cout<<c;
     cout<<" <------ CRC Bits\n";
     return remainder;
}
void CRC(){
     cout<<setw(71)<<"|* CYCLIC REDUNDANCY CHECK *|\n\n";
     string data;
     string bit = "";
     string divisor;
     cout<<"* Enter Data to be Transmitted: "; cin >> data;
     cout<<"* Enter CRC Divisor: ";cin >> divisor;
     cout<<"\n\n";
     cout<<"* Data to be Transmitted: \n";

     for(int i = 0; i < 30; i++) cout<<"=";
     cout<<"\n";
     cout<<setw(10)<<"CHARACTER";
     cout<<setw(18)<<"BITDATA\n";
     for(int i = 0; i < 30; i++) cout<<"=";
     cout<<"\n";

     for(char &c: data){
          Sleep(75);
          c = toupper(c);
          bit += bitData[c-'A'];
          cout<<setw(5)<<c;
          cout<<setw(23)<<bitData[c - 'A'];
          cout<<"\n";
     }
     cout<<"\n";
     cout<<"* Divisor Polynomial:           ";
     for(int i = 0; i < divisor.length(); i++){
          if(divisor[i] == '1') {
               if(i == divisor.length()-1) cout<<"1";
               else cout<<"x^"<<divisor.length()-i-1;
               if(i != divisor.length()-1) cout<<" + ";
          }
     }
     cout<<"\n";
     cout<<"* Bit Stream to be Transmitted: "<<bit<<"\n\n";

     Sleep(200);
     for(int i = 0; i < 54; i++) cout<<"="; cout<<"\n";
     cout<<"Performing CRC Modulo-2 Division to generate CRC bits: \n";
     for(int i = 0; i < 54; i++) cout<<"="; cout<<"\n";

     cout<<"Press Any Key to Continue.\n";
     _getch();

     string bitCopy = bit;
     for(int i = 0; i < divisor.length()-1; i++) bitCopy += '0';
     string remainder = CRC_helper(bitCopy,divisor);
     bit += remainder;
     cout<<"Final Bit Stream to be transmitted: "<<bit<<" (Data + CRC bits)\n";

     cout<<"Press Any Key to Inject Noise and Transmit.\n";
     _getch();

     printReceiverSide();
     int errorCount = 4;
     while(errorCount){
          int r = rand() % bit.length();
          if(bit[r] == '1') bit[r] = '0';
          else bit[r] = '1';
          errorCount--;
     }

     cout<<"* Bit Stream at Receiver Side: "<<bit<<"\n";
     cout<<"* Divisor Polynomial:          ";
     for(int i = 0; i < divisor.length(); i++){
          if(divisor[i] == '1') {
               if(i == divisor.length()-1) cout<<"1";
               else cout<<"x^"<<divisor.length()-i-1;
               if(i != divisor.length()-1) cout<<" + ";
          }
     }
     cout<<"\n";

     for(int i = 0; i < 54; i++) cout<<"="; cout<<"\n";
     cout<<"Performing CRC Modulo-2 Division to generate CRC bits: \n";
     for(int i = 0; i < 54; i++) cout<<"="; cout<<"\n";

     cout<<"Press Any Key to Continue.\n";
     _getch();
     remainder = CRC_helper(bit,divisor);
     cout<<"\n* Remainder is not 0.\n";
     cout<<"* Data is Rejected";
}

int main(){
     srand(time(NULL));
     printWelcome();

     char ch = 'y';

     while(ch == 'y'){
          cout<<"Choose one of the following Error Detection Algorithm: \n\n";
          cout<<"1. Single Parity Check\n";
          cout<<"2. 2D Parity Check\n";
          cout<<"3. CheckSum\n";
          cout<<"4. Cyclic Redundancy Check\n\n";

          cout<<"Enter Choice: ";
          int choice;
          cin >> choice;

          printSenderSide();

          switch(choice){
               case 1: singleParityCheck(); break;
               case 2: twoDParityCheck(); break;
               case 3: checkSum(); break;
               case 4: CRC();
          }

          cout<<"\n\nRetry? (y/n): "; cin >> ch;
     }

}
