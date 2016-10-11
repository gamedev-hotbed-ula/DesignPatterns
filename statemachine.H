# ifndef STATEMACHINE_H
# define STATEMACHINE_H

# include <cassert>
# include <stdexcept>

template <class GameEntityType>
class State
{
public:
  virtual void enter(GameEntityType *) = 0;

  virtual void exec(GameEntityType *) = 0;

  virtual void exit(GameEntityType *) = 0;
};

template <class GameEntityType>
class StateMachine 
{
  State<GameEntityType> * current_state;
  State<GameEntityType> * last_state;

public:
  StateMachine(State<GameEntityType> * initial_state)
    : current_state(initial_state), last_state(nullptr)
  {
    if (current_state == nullptr)
      throw std::logic_error("The state machine needs an initial state");
  }

  GameEntityType * to_child_ptr()
  {
    return static_cast<GameEntityType *>(this);
  }

  operator GameEntityType & ()
  {
    return *to_child_ptr();
  }

  void exec()
  {
    assert(current_state != nullptr);
    current_state->exec(to_child_ptr());
  }

  void change_state(State<GameEntityType> * new_state)
  {
    assert(new_state != nullptr);
    
    current_state->exit(to_child_ptr());
    last_state = current_state;
    current_state = new_state;
    current_state->enter(to_child_ptr());
  }

  void set_last_state()
  {
    if (last_state == nullptr)
      return;
    
    change_state(last_state);
  }
};

# endif // STATEMACHINE_H
