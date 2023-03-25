class Solution {
private:
bool checkEqual(int a[26],int b[26]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
        return 1;
}
public:
    bool checkInclusion(string s1, string s2) {
        //store count of all characters in s1
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a'; 
            count1[index]++;   //stores the count of that character at its position
        }
        //now,travesrse s2 in windows of size s1
        int i=0;
        int windowSize=s1.length();
        int count2[26]={0};
        while(i<windowSize && i<s2.length()){
            int index=s2[i]-'a';
            count2[index]++;
            i++;
        }
        if(checkEqual(count1,count2)){
            return 1;
        }
        //if false,process subsequent windows
        while(i<s2.length()){
            char newchar=s2[i];
            int index=newchar-'a';
            count2[index]++;   //adding new character for processsing

            char oldchar=s2[i-windowSize];
            index=oldchar-'a';
            count2[index]--;  //removing the old character
              
              i++;
        if(checkEqual(count1,count2))  //inside while bcos each new window has to be checked
            return 1;
        }
        return 0;

    }
};
