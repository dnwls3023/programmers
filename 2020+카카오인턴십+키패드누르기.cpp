#include <string>
#include <vector>
#include <cmath> 
#include <iostream>
using namespace std;

// 2020 카카오 인턴십 키패드누르기

// 문제 후기 : 생각보다 어려웠음.

pair<int,int> mapping[12] = {{3,1},{0,0},{0,1},
                             {0,2},{1,0},{1,1},
                             {1,2},{2,0},{2,1},{2,2},{3,0},{3,2}};

// -1은 없는거 0은 왼손 1은 오른손
int pos[10] = {-1,0,-1,1,0,-1,1,0,-1,1};

// a와 b의 각각의 좌표값을 구한 뒤 , 절댓값의 차의 합을 리턴한다.
int distance(int a,int b){ 
    pair<int,int> p1 = mapping[a];
    pair<int,int> p2 = mapping[b];
    
    int dist1 = abs(mapping[a].first - mapping[b].first);
    int dist2 = abs(mapping[a].second - mapping[b].second);
    
    return dist1+dist2;
}


//본체

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int size = numbers.size();
    
    // 초기상태 *, #
    int last_hand_l = 10,last_hand_r=11;
    
    for(int i = 0; i<size;++i){
        if(pos[numbers[i]] == 1){
            answer.push_back('R');
            last_hand_r = numbers[i];
        }
        else if(pos[numbers[i]] == 0){
            answer.push_back('L');
            last_hand_l = numbers[i];
        }
        else if(pos[numbers[i]] == -1){
            
            // 왼손 터치
            if(distance(last_hand_l,numbers[i])<
               distance(last_hand_r,numbers[i])){
                answer.push_back('L');
                last_hand_l = numbers[i];
            }
            // 오른손 터치
            else if(distance(last_hand_l,numbers[i])>
               distance(last_hand_r,numbers[i])){
                answer.push_back('R');
                last_hand_r = numbers[i];
            }
            else{
                if(hand=="left"){
                    answer.push_back('L');
                    last_hand_l = numbers[i];
                }
                else{
                    answer.push_back('R');
                    last_hand_r = numbers[i];
                }
                    
            }    
        }
        
            
        
    }
    return answer;
}




/*
// 디버깅용
string solution(vector<int> numbers, string hand) {
    string answer = "";
    //distance 함수가 잘 작동하는지
    // 왼손위치 4, 눌러야할 숫자 5 -> 왼손거리 1
    // 오른손위치 3, 눌러야할 숫자 5 -> 오른손거리 2
    cout<<distance(4,5)<<endl;
    cout<<distance(2,5)<<endl;
    return answer;
}
*/
