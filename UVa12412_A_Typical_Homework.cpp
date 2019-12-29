#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const double EPS = 1e-5;
const int INF = 0x3f3f3f3f;

struct Student {
    string SID, name;
    int CID;
    int Ch, Ma, En, Pr;
    int id, rank;
    double ave_score;
    int tot_score;
} stu[500];
int cnt;

// 是否已存储该SID
map<string, bool> SID_table;

// 以总分为标准排序
bool CmpScore(struct Student a, struct Student b) {
    return a.tot_score > b.tot_score;
}

// 以添加顺序为标准排序，确保查询时顺序无误
bool CmpId(struct Student a, struct Student b) {
    return a.id < b.id;
}

void PrintMenu() {
    printf("Welcome to Student Performance Management System (SPMS).\n\n"
           "1 - Add\n"
           "2 - Remove\n"
           "3 - Query\n"
           "4 - Show ranking\n"
           "5 - Show Statistics\n"
           "0 - Exit\n\n");
}

void Add() {
    string s;
    while (true) {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        cin >> s;
        if (s == "0") break;
        if (SID_table[s]) {
            printf("Duplicated SID.\n");
            char c;
            while ((c = getchar()) != '\n');
            continue;
        }

        stu[cnt].SID = s;
        cin >> stu[cnt].CID >> stu[cnt].name >> stu[cnt].Ch >> stu[cnt].Ma >> stu[cnt].En >> stu[cnt].Pr;
        stu[cnt].id = cnt;
        stu[cnt].tot_score = stu[cnt].Ch + stu[cnt].Ma + stu[cnt].En + stu[cnt].Pr;
        stu[cnt].ave_score = stu[cnt].tot_score / 4.0 + EPS;
        SID_table[s] = true;
        
        cnt++;
    }
}

void Remove() {
    string s;
    while (true) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        cin >> s;
        if (s == "0") break;

        int cnt_r = 0;
        for (int i = 0; i < cnt; i++) {
            if (s == stu[i].SID || s == stu[i].name) {
                SID_table[stu[i].SID] = false;
                stu[i].SID = stu[i].name = "";
                stu[i].CID = 0;
                stu[i].tot_score = -1; // 避免排序错误
                stu[i].id = INF; // 同样避免排序错误

                cnt_r++;
            }
        }

        printf("%d student(s) removed.\n", cnt_r);
    }
}

void Query() {
    sort(stu, stu + cnt, CmpScore);
    for (int i = 0; i < cnt; i++) {
        if (stu[i].tot_score == stu[i-1].tot_score) stu[i].rank = stu[i-1].rank;
        else stu[i].rank = i + 1;
    }
    sort(stu, stu + cnt, CmpId);

    string s;
    while (true) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        cin >> s;
        if (s == "0") break;
        for (int i = 0; i < cnt; i++) {
            if (stu[i].SID == s || stu[i].name == s) {
                printf("%d %s %d %s %d %d %d %d %d %.2f\n",
                       stu[i].rank, stu[i].SID.c_str(), stu[i].CID, stu[i].name.c_str(),
                       stu[i].Ch, stu[i].Ma, stu[i].En, stu[i].Pr,
                       stu[i].tot_score, stu[i].ave_score);
            }
        }
    }
    
}

void Ranking() {
    printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
}

void Statistics() {
    printf("Please enter class ID, 0 for the whole statistics.\n");
    int target_CID;
    cin >> target_CID;
    
    int cnt_subject[4] = {0}, cnt_passed[5] = {0}, tot[4] = {0}, cnt_stu = 0;
    for (int i = 0; i < cnt; i++) {
        if ((stu[i].CID == target_CID || !target_CID) && SID_table[stu[i].SID]) {
            cnt_stu++;
            tot[0] += stu[i].Ch;
            tot[1] += stu[i].Ma;
            tot[2] += stu[i].En;
            tot[3] += stu[i].Pr;
            int passed = 0;
            if (stu[i].Ch >= 60) {
                cnt_subject[0]++;
                passed++;
            }
            if (stu[i].Ma >= 60) {
                cnt_subject[1]++;
                passed++;
            }
            if (stu[i].En >= 60) {
                cnt_subject[2]++;
                passed++;
            }
            if (stu[i].Pr >= 60) {
                cnt_subject[3]++;
                passed++;
            }
            for (int i = 1; i <= passed; i++) cnt_passed[i]++;
        }
    }
    printf("Chinese\n"
           "Average Score: %.2f\n"
           "Number of passed students: %d\n"
           "Number of failed students: %d\n\n"
           "Mathematics\n"
           "Average Score: %.2f\n"
           "Number of passed students: %d\n"
           "Number of failed students: %d\n\n"
           "English\n"
           "Average Score: %.2f\n"
           "Number of passed students: %d\n"
           "Number of failed students: %d\n\n"
           "Programming\n"
           "Average Score: %.2f\n"
           "Number of passed students: %d\n"
           "Number of failed students: %d\n\n"
           "Overall:\n"
           "Number of students who passed all subjects: %d\n"
           "Number of students who passed 3 or more subjects: %d\n"
           "Number of students who passed 2 or more subjects: %d\n"
           "Number of students who passed 1 or more subjects: %d\n"
           "Number of students who failed all subjects: %d\n\n",
           tot[0] / (double)cnt_stu + EPS, cnt_subject[0], cnt_stu - cnt_subject[0],
           tot[1] / (double)cnt_stu + EPS, cnt_subject[1], cnt_stu - cnt_subject[1],
           tot[2] / (double)cnt_stu + EPS, cnt_subject[2], cnt_stu - cnt_subject[2],
           tot[3] / (double)cnt_stu + EPS, cnt_subject[3], cnt_stu - cnt_subject[3],
           cnt_passed[4], cnt_passed[3], cnt_passed[2], cnt_passed[1], cnt_stu - cnt_passed[1]);
}

int main() {
    while (true) {
        PrintMenu();

        int choice;
        cin >> choice;
        if (!choice) break;
        switch (choice) {
            case 1:
                Add();
                break;
            case 2:
                Remove();
                break;
            case 3:
                Query();
                break;
            case 4:
                Ranking();
                break;
            case 5:
                Statistics();
        }
    }

    return 0;
}