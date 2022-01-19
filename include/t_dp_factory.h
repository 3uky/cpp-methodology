#ifndef T_DP_FACTORY_H
#define T_DP_FACTORY_H

#include <memory>

using namespace std;

class Stooge
{
  public:
    // Factory Method
    static unique_ptr<Stooge> make_stooge(int choice);
    virtual void slap_stick() = 0;
};

class Larry: public Stooge
{
  public:
    void slap_stick()
    {
        cout << "Larry: poke eyes\n";
    }
};
class Moe: public Stooge
{
  public:
    void slap_stick()
    {
        cout << "Moe: slap head\n";
    }
};
class Curly: public Stooge
{
  public:
    void slap_stick()
    {
        cout << "Curly: suffer abuse\n";
    }
};

unique_ptr<Stooge> Stooge::make_stooge(int choice)
{
  if (choice == 1)
    return make_unique<Larry>();
  else if (choice == 2)
    return make_unique<Moe>();
  else
    return make_unique<Curly>();
}

class T_dp_factory
{
public:
    static void test()
    {
      vector<unique_ptr<Stooge>> roles;
      int choice;
      while (true)
      {
        cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
        cin >> choice;
        if (choice == 0)
          break;
        roles.push_back(Stooge::make_stooge(choice));
      }
      for (auto &role : roles)
        role->slap_stick();
    }

};

#endif // T_DP_FACTORY_H
