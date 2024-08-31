#include <iostream>
#include <time.h>
using namespace std;

struct Player {
    string name;
    int games_played;
    int total_points;
    int total_assists;
    int total_rebounds;
};

struct Team {
    string team_name;
    Player players[5];
};

float* points_avg(Team *n, float *total);
void isWins(Team t1, Team t2);
void best_team(Team teams[], int m);
void find_best_player(Team t1, Player &bestPlayer);
void create_team(Team &t);
void showMenu();
int main() {

    showMenu();

    return 0;
}

float* points_avg(Team *n, float *total) {
    *total = 0; 
    for(int i = 0; i < 5; i++) { 
        *total += static_cast<float>(n->players[i].total_points) / n->players[i].games_played;
    }
    *total /= 5; 
    return total;
}
void isWins(Team t1, Team t2){
    float sum1=0;
    float sum2=0;
    srand(time(0));
    int x = rand()%30;
    int y= rand()%30;
    
    if (points_avg(&t1, &sum1)+x> points_avg(&t1, &sum2)+y) cout<<t1.team_name<<" wins!"<<endl;
    else if(points_avg(&t1, &sum1)+x< points_avg(&t1, &sum2)+y) cout<<t2.team_name<<" wins!"<<endl;
    else cout<<"That's a tie game!"<<endl;

}
void team_stats(Team *n) {
    float totalp = 0;
    float totala = 0;
    float totalr = 0;
    for(int i = 0; i < 5; i++) {
        totalp += n->players[i].total_points;
        totala += n->players[i].total_assists;
        totalr += n->players[i].total_rebounds;
    }
    cout << "Total points: " << totalp << endl;
    cout << "Total Asist: " << totala << endl;
    cout << "Total Ribaund: " << totalr << endl;
}

void best_team(Team teams[], int m){
    float total=0;
    float max=0;
    string name; 
    for(int i=0; i<m; i++){
        float totalp = 0;
        float totala = 0;
        float totalr = 0;
        for(int j = 0; j < 5; j++) {
            totalp += teams[i].players[j].total_points;
            totala += teams[i].players[j].total_assists;
            totalr += teams[i].players[j].total_rebounds;
        }
        total = 0.35*totalp + 0.4*totalr + 0.25*totala;
        if (total > max) {
            max = total;
            name = teams[i].team_name; 
        }
    }
    cout << "The best team is: " << name << endl;
}

void find_best_player(Team t1, Player &bestPlayer) {
    float highestAverage = static_cast<float>(t1.players[0].total_points) / t1.players[0].games_played;
    bestPlayer = t1.players[0];

    for (int i = 1; i < 5; i++) {
        float averagePoints = static_cast<float>(t1.players[i].total_points) / t1.players[i].games_played;
        if (averagePoints > highestAverage) {
            highestAverage = averagePoints;
            bestPlayer = t1.players[i];
        }
    }
}
void create_team(Team &t){
    cout<<"Enter the team's name: ";
    cin>>t.team_name;
    cout<<endl;
    cout << "Enter the player information: " << endl;
    for(int i = 0; i < 5; i++) {  
       cout << "Player " << i + 1 << " Adı: ";
       cin >> t.players[i].name;
       cout << "Games Played: ";
       cin >> t.players[i].games_played;
       cout << "Total Points: ";
       cin >> t.players[i].total_points;
       cout << "Total Assists: ";
       cin >> t.players[i].total_assists;
       cout << "Total Ribaund: ";
       cin >> t.players[i].total_rebounds;
    }
}
void showMenu(){
    float total = 0;
    int n,i;
    cout<<"Enter the number of teams: "<<endl;
    cin>>n;
    Team t[n];
    for(i=0; i<n; i++){
        create_team(t[i]);
    }
    

    while(1){
        int u;
        cout<<"Enter the operation number"<<endl;
        cout<<"1. find the average points"<<endl;
        cout<<"2. find the best player"<<endl;
        cout<<"3. find the team's stats"<<endl;
        cout<<"4. find the best team"<<endl;
        cout<<"5. find the simulation guess"<<endl;
        cout<<"6. exit"<<endl;
        cin>>u;
        if(u==1){
            for(i=0; i<n; i++){
                float *a = points_avg(&t[i], &total);
                cout << "Average points: " << *a << endl;
            }
        }
        else if(u==2){
            for(i=0; i<n; i++){
                Player bestPlayer;
                find_best_player(t[i], bestPlayer);
                cout << "Best Player: " << bestPlayer.name << endl;
            }
        }
        else if(u==3){
            for(i=0; i<n; i++){
                team_stats(&t[i]);
            }
        }
        else if(u==4){
            best_team(t,n);
        }
        else if(u==5){
            int k, j;
            cout << "Enter the two team's index numbers: ";
            cin >> k >> j;

            if(k >= 0 && k < n && j >= 0 && j < n) {
                 isWins(t[k], t[j]);
            } else {
                 cout << "Invalid team indices!" << endl;
                }
        }
        else if(u==6){
            cout<<"Program ended!"<<endl;
            break;
        }
        else cout<<"Enter a valid operation"<<endl;
    }
}