#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <cassert>
#include <stdexcept>
#include <unordered_map> 

template <class ConcreteStateMachine>
class State
{
public:
  virtual void on_enter(ConcreteStateMachine *)
  {
    //empty
  }

  virtual void update(ConcreteStateMachine *, double)
  {
    // empty
  }

  virtual void on_exit(ConcreteStateMachine *)
  {
    // empty
  }
};

template <class ConcreteStateMachine,
	  typename Key=std::string>
class StateMachine 
{
  using Table = std::unordered_map<Key, State<ConcreteStateMachine> *>;

  Table states;
  
  State<ConcreteStateMachine> * current_state;
  State<ConcreteStateMachine> * last_state;

  void change_state(State<ConcreteStateMachine> * new_state)
  {
    assert(new_state != nullptr);
    
    current_state->on_exit(me());
    last_state = current_state;
    current_state = new_state;
    current_state->on_enter(me());
  }

public:
  StateMachine()
    : current_state(nullptr), last_state(nullptr)
  {
    // empty
  }

  void add_state(const Key & k, State<ConcreteStateMachine> * s)
  {
    states.emplace(k, s);
  }

  void set_initial_state(const Key & k)
  {
    if (current_state != nullptr)
      throw std::logic_error("The state machine has already been initialized.");
    auto search = states.find(k);
    if (search == states.end())
      throw std::domain_error("Error in state name");
    current_state = search->second;
  }

  void clear()
  {
    states.clear();
    current_state = nullptr;
    last_state = nullptr;
  }

  typename Table::size_type size() const
  {
    return states.size();
  }

  ConcreteStateMachine * me()
  {
    return static_cast<ConcreteStateMachine *>(this);
  }

  const ConcreteStateMachine * const_me() const
  {
    return static_cast<const ConcreteStateMachine *>(this);
  }

  operator ConcreteStateMachine & ()
  {
    return me();
  }

  void update(double dt)
  {
    assert(current_state != nullptr);
    current_state->update(me(), dt);
  }

  void change_state(const Key & k)
  {
    auto search = states.find(k);
    if (search == states.end())
      throw std::domain_error("Error in state name");
    change_state(search->second);
  }

  void set_last_state()
  {
    if (last_state == nullptr)
      return;
    
    change_state(last_state);
  }
};

# endif // STATEMACHINE_H
