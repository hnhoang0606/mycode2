#include "ui.h"

void ui :: DisplayMember()
{
    cout << "display Member in table: " <<endl;
    cout << endl;
    MemberData memberData("Member.txt");
    for(int i = 0 ; i < memberData.GetSize(); i++ )
    {   
        Member member = memberData.Get(i);
        cout << member.ToString()<<endl;
    }
}

void ui ::EditMember()
{
    MemberData memberData("Member.txt");
    cout << "please enter id of the table you what to edit:  ";
    int choice;
    cin >> choice; choice --;
    cout <<"old data: " << memberData.Get(choice).ToString()<<endl;
    Member member = EnterMemberInfor();
    memberData.Set(member,choice);
    cout << "New Data: ";
    //cout << memberData.Get(choice).ToString()<<endl;
    memberData.Export("Member.txt");
    DisplayMember();
}

void ui ::CreateMember()
{
    cout <<"Create Member " <<endl;
    MemberData memberData("Member.txt");
    Member member = EnterMemberInfor();
    memberData.PushBack(member);
    memberData.Export("Member.txt");
    DisplayMember();
}

void ui :: DeleteMember()
{   
    MemberData memberData("Member.txt");
    DisplayMember();
    int n;
    cout <<" Enter Id that you want to delete"<<endl;
    cout <<" Id: ";
    cin >> n; n--;
    memberData.Delete(n);
    memberData.Export("Member.txt");
    cout << "Deleted"<<endl;
    DisplayMember();
}

Member EnterMemberInfor()
{   
    Member member;
    cout <<"Enter Member Information"<<endl;
    cout <<" Enter MemberID:  ";
    int i; cin >>i;
    member.SetMemberID(i);
    cout <<" Enter MemberName: ";
    string s; cin >> s;
    member.SetMemberName(s);
    return member;
}

// void ui :: DeleteMember()
// {   
//     MemberData memberData("Member.txt");
//     DisplayMember();
//     int n;
//     cout <<" Enter Id that you want to delete"<<endl;
//     cout <<" Id: ";
//     cin >> n; n--;
//     memberData.Delete(n);
//     DisplayMember();
//     memberData.Export("Member.txt");
// }


// void ui :: MainInterFace()
// {   
//     cout <<"tam ok";
//     //Delete();
//     CreateMember();
//     DisplayMember();
//     cout <<endl;
//     cout <<"___________________"<<endl;
//     // EditMember();
//     DeleteMember();
//     DisplayMember();
// }


void ui :: MainInterFace()
{
    int choice;
    cout <<"choose funtion"<<endl;
    cout <<"1: Display"<<endl;
    cout <<"2: Edit"<<endl;
    cout <<"3: Create"<<endl;
    cout <<"4: Delete"<<endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        DisplayMember();
        break;
    case 2:
        EditMember();
        break;
    case 3: 
        CreateMember();
        break;
    case 4:
        DeleteMember();
        break;
    
    }
}