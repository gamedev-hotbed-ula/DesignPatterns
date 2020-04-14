# ifndef MINER_H
# define MINER_H

# include <miner_states.H>

class Miner : public StateMachine<Miner>
{
  double stamina;
  double thirst;
  double bladder;

public:
  Miner()
    : stamina(100), thirst(0), bladder(0)
  {
    add_state("working", MinerWorking::get_ptr_instance());
    add_state("sleeping", MinerSleeping::get_ptr_instance());
    add_state("drinking", MinerDrinking::get_ptr_instance());
    add_state("wc", MinerInWc::get_ptr_instance());
    set_initial_state("working");
  }

  const double & get_stamina() const { return stamina; }

  const double & get_thirst() const { return thirst; }
  
  const double & get_bladder() const { return bladder; }

  void add_stamina(double val) { stamina += val; }

  void add_thirst(double val) { thirst += val; }

  void add_bladder(double val) { bladder += val; }
};

# endif // MINER_H
