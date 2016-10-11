# ifndef MINER_H
# define MINER_H

# include <miner_states.H>

class Miner : public StateMachine<Miner>
{
  size_t stamina;
  size_t thirst;
  size_t bladder;

public:
  Miner()
    : StateMachine<Miner>(MinerWorking::get_ptr_instance()),
    stamina(100), thirst(0), bladder(0)
  {
    /* empty */
  }

  const size_t & get_stamina() const { return stamina; }

  const size_t & get_thirst() const { return thirst; }
  
  const size_t & get_bladder() const { return bladder; }

  void add_stamina(int val) { stamina += val; }

  void add_thirst(int val) { thirst += val; }
  
  void add_bladder(int val) { bladder += val; }
};

# endif // MINER_H
