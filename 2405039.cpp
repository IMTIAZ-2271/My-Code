#include <bits/stdc++.h>
// Include header files as required

using namespace std;
//===============================================================
class PartyMember
{
    int member_id;        // a unique ID assigned to each member by the political party
    string name;          // name of the member
    long asset_value;     // net asset of the member
    string nominated_for; // name of the constituency if this member is nominated by his party for running election
    // You are not allowed to add any other member variable in this class

public:
    // Write a default constructor for this class. Initialize data members as deem appropriate.
    PartyMember()
    {
        member_id = 0;
        name = "";
        asset_value = 0;
        nominated_for = "";
    }

    // Write other parameterize constructors as required.
    PartyMember(const string name, const int asset_value)
    {
        this->name = name;
        this->asset_value = asset_value;
        member_id = 0;
        nominated_for = "";
    }

    // Write the setter functions for this class
    void set_constituency(const string nominated_for)
    {
        this->nominated_for = nominated_for;
    }
    void set_member_id(const int member_id)
    {
        this->member_id = member_id;
    }
    void set_asset_value(const long asset_value)
    {
        this->asset_value = asset_value;
    }
    void set_member_name(const string name)
    {
        this->name = name;
    }
    // Write the getter functions for this class
    string get_constituency() const
    {
        return nominated_for;
    }

    int get_member_id() const
    {
        return member_id;
    }

    long get_asset_value() const
    {
        return asset_value;
    }
    string get_member_name() const
    {
        return name;
    }

    void show_member_details() const
    {
        // Print member details in the format shown in the given sample output
        if (nominated_for != "")
        {
            cout << "ID: " << member_id << ", Name: " << name << ", Asset: " << asset_value << ", Constituency: " << nominated_for << endl;
        }
        else
        {
            cout << "ID: " << member_id << ", Name: " << name << ", Asset: " << asset_value << endl;
        }
    }

    // Add any other helper functions as required
    PartyMember(const PartyMember &pm)
    {
        this->member_id = pm.member_id;
        this->name = pm.name;
        this->asset_value = pm.asset_value;
        this->nominated_for = pm.nominated_for;
    }
    PartyMember &operator=(const PartyMember &pm)
    {
        this->member_id = pm.member_id;
        this->name = pm.name;
        this->asset_value = pm.asset_value;
        this->nominated_for = pm.nominated_for;
        return *this;
    }

    
};
//===============================================================
class PoliticalParty
{
    string name;                // name of the political party
    PartyMember *members[1000]; // Array of pointers to PartyMember objects; Allocate an object to a pointer when a member is added. Assume that there will be at most 1000 members in a party
    int member_count;           // count of members in the party
    int member_id_serial;       // Keep track of the next member ID to be assigned
    int nominated_count;        // count of nominated members in the party
    // Add other member variables as required and justified

public:
    PoliticalParty()
    {
        name = "";
        member_count = 0;
        nominated_count = 0;
        member_id_serial = 1;
    }

    // Write a copy constructor for this class
    PoliticalParty(const PoliticalParty &pp)
    {
        this->name = pp.get_name();
        this->member_count = pp.get_member_count();
        this->nominated_count = pp.get_nominated_count();
        this->member_id_serial = pp.get_member_id_serial();
        for (int i = 0; i < member_count; i++)
        {
            this->members[i] = new PartyMember(*(pp.members[i]));
        }
    }
    PoliticalParty &operator=(const PoliticalParty &pp)
    {
        for (int i = 0; i < member_count; i++)
        {
            delete members[i];
        }
        this->name = pp.get_name();
        this->member_count = pp.get_member_count();             
        this->member_id_serial = pp.get_member_count(); 
        this->nominated_count = pp.get_nominated_count();
        for (int i = 0; i < member_count; i++)
        {
            this->members[i] = new PartyMember(*(pp.members[i]));
        }
        return *this;
    }

    // Write other parameterize constructors as required
    PoliticalParty(const string name)
    {
        this->name = name;
        member_count = 0;
        member_id_serial = 1;
        nominated_count = 0;
    }

    // Write a destructor for this class
    ~PoliticalParty()
    {
        for (int i = 0; i < member_count; i++)
        {
            delete members[i];
        }
    }

    // Write setter functions for this class
    void set_name(const string name)
    {
        this->name = name;
    }
    void set_member_count(const int member_count)
    {
        this->member_count = member_count;
    }
    void set_member_id_serial(const int id)
    {
        this->member_id_serial = id;
    }
    void set_nominated_count(const int count)
    {
        this->nominated_count = count;
    }

    // Write getter functions for this class
    string get_name() const
    {
        return name;
    }
    int get_member_count() const
    {
        return member_count;
    }
    int get_member_id_serial() const
    {
        return member_id_serial;
    }
    int get_nominated_count() const
    {
        return nominated_count;
    }


    PartyMember search_member(string constituency)
    {
        // Returns the member nominated for the given constituency. If not found, return an empty object.
        if (member_count <= 0)
        {
            return PartyMember();
        }
        for (int i = 0; i < member_count; i++)
        {
            if (members[i]->get_constituency() == constituency)
            {
                return *(members[i]);
            }
        }
        return PartyMember();
    }

    void join_party(PartyMember m)
    {
        // Add the member m to this party. Assign id sequentially to the new member.
        members[member_count] = new PartyMember(m);
        members[member_count]->set_member_id(member_id_serial++);
        members[member_count]->set_constituency("");
        member_count++;
    }

    void leave_party(int id)
    {
        // Remove the member with the given id from this party. Rearrange the list such that all the members are consecutive, i.e., there is no hole in the list. When a member leaves a party, his id is never reused.
        for (int i = 0; i < member_count; i++)
        {
            if (members[i]->get_member_id() == id)
            {
                delete members[i];
                for (int j = i; j < member_count - 1; j++)
                {
                    members[j] = members[j + 1];
                }
                member_count--;
                members[member_count] = nullptr;
                return;
            }
        }
        return;
    }

    void join_party(PoliticalParty &pp)
    {
        // Add all the members of pp to this party and remove them from pp. Assign ids sequentially to the new members in this party. When a member joins from one party to another, his nomination, if given, from the old party is automatically cancelled.
        int old_member_count = pp.get_member_count();
        for(int i=0; i<old_member_count; i++)
        {
            this->join_party(*(pp.members[i]));
            delete pp.members[i];
        }
        pp.set_member_count(0);
        pp.set_nominated_count(0);
    }

    void nominate_member(int id, string constituency)
    {
        // Nominate the member with given id for the constituency
        for (int i = 0; i < member_count; i++)
        {
            if (members[i]->get_member_id() == id)
            {
                members[i]->set_constituency(constituency);
                nominated_count++;
                return;
            }
        }
        return;
    }

    void show_nominated_members() const
    {
        // Show details of the members nominated for the election. Match the format as given in the expected output.
        
        cout << "Nominated Members of " << name << ":" << endl;
        if (nominated_count <= 0)
        {
            cout << "No nominated members found." << endl;
            cout << endl;
            return;
        }
        for (int i = 0; i < member_count; i++)
        {
            if (members[i]->get_constituency() != "")
            {
                members[i]->show_member_details();
            }
        }
        cout << endl;
    }

    void cancel_nomination(int id)
    {
        // Cancel nomination of the member with the given id
        for (int i = 0; i < member_count; i++)
        {
            if (members[i]->get_member_id() == id)
            {
                members[i]->set_constituency("");
                nominated_count--;
                return;
            }
        }
        return;
    }

    PoliticalParty form_new_party(string name)
    {
        //Form a new party with the members who have been denied nomination	from this party
        PoliticalParty new_party(name);

        int i = 0;              
        while (i < member_count) 
        {
            if (members[i]->get_constituency() == "")
            {
                new_party.join_party(*members[i]);
                leave_party(members[i]->get_member_id());
            }
            else
            {
                i++;
            }
        }
        return new_party;
    }

    void show_all_members()
    {
        // Print details info of all the members of this party in the format shown in the given expected output

        cout << "Members of " << name << ":" << endl;
        if (member_count <= 0)
        {
            cout << "No members found." << endl;
            cout << endl;
            return;
        }
        for (int i = 0; i < member_count; i++)
        {
            members[i]->show_member_details();
        }
        cout << endl;
    }

    // Add any other helper function as required and justified
};
//=======================================
int main()
{
    PartyMember abc1("Mr. A", 100000000);
    PartyMember abc2("Mr. B", 4000000);
    PartyMember abc3("Mr. C", 20000000);
    PoliticalParty p1("ABC");
    p1.join_party(abc1);
    p1.join_party(abc2);
    p1.join_party(abc3);
    p1.show_all_members();

    p1.nominate_member(1, "DHK-10");
    PartyMember pm = p1.search_member("DHK-10");
    cout << "Details of the member nominated for DHK-10 constituency:" << endl;
    pm.show_member_details();
    cout << endl;

    p1.nominate_member(2, "CUM-3");
    p1.nominate_member(3, "SYL-1");
    p1.show_nominated_members();

    PartyMember xyz1("Mr. X", 1000000);
    PartyMember xyz2("Mr. Y", 3000000);

    PoliticalParty p2("XYZ");
    p2.join_party(xyz1);
    p2.join_party(xyz2);
    p2.show_all_members();

    p1.join_party(p2);
    p1.show_all_members();
    p2.show_all_members();

    PartyMember xyz3("Mr. Z", 5000000);
    p2.join_party(xyz3);
    p2.show_all_members();

    p1.cancel_nomination(1);
    p1.cancel_nomination(3);
    p1.nominate_member(4, "CUM-3");
    p1.nominate_member(5, "SYL-1");
    p1.show_nominated_members();

    PoliticalParty p3 = p1.form_new_party("Renegades");
    p1.show_all_members();
    p3.show_all_members();
}

/* Expected Output
Members of ABC:
ID: 1, Name: Mr. A, Asset: 100000000
ID: 2, Name: Mr. B, Asset: 4000000
ID: 3, Name: Mr. C, Asset: 20000000

Details of the member nominated for DHK-10 constituency:
ID: 1, Name: Mr. A, Asset: 100000000, Constituency: DHK-10

Nominated Members of ABC:
ID: 1, Name: Mr. A, Asset: 100000000, Constituency: DHK-10
ID: 2, Name: Mr. B, Asset: 4000000, Constituency: CUM-3
ID: 3, Name: Mr. C, Asset: 20000000, Constituency: SYL-1

Members of XYZ:
ID: 1, Name: Mr. X, Asset: 1000000
ID: 2, Name: Mr. Y, Asset: 3000000

Members of ABC:
ID: 1, Name: Mr. A, Asset: 100000000, Constituency: DHK-10
ID: 2, Name: Mr. B, Asset: 4000000, Constituency: CUM-3
ID: 3, Name: Mr. C, Asset: 20000000, Constituency: SYL-1
ID: 4, Name: Mr. X, Asset: 1000000
ID: 5, Name: Mr. Y, Asset: 3000000

Members of XYZ:
No members found.

Members of XYZ:
ID: 3, Name: Mr. Z, Asset: 5000000

Nominated Members of ABC:
ID: 2, Name: Mr. B, Asset: 4000000, Constituency: CUM-3
ID: 4, Name: Mr. X, Asset: 1000000, Constituency: CUM-3
ID: 5, Name: Mr. Y, Asset: 3000000, Constituency: SYL-1

Members of ABC:
ID: 2, Name: Mr. B, Asset: 4000000, Constituency: CUM-3
ID: 4, Name: Mr. X, Asset: 1000000, Constituency: CUM-3
ID: 5, Name: Mr. Y, Asset: 3000000, Constituency: SYL-1

Members of Renegades:
ID: 1, Name: Mr. A, Asset: 100000000
ID: 2, Name: Mr. C, Asset: 20000000
*/
