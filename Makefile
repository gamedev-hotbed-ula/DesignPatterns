CXX = clang++ -std=c++14

DEBUG = -g -O0

OPT = -Ofast

INCLUDE = -I.

all: test-singleton test-statemachine

test-singleton: singleton.H test-singleton.C
	$(CXX) $(DEBUG) $(INCLUDE) $@.C -o $@

test-statemachine: miner_states.o statemachine.H miner.H test-statemachine.C
	$(CXX) $(DEBUG)  $(INCLUDE) $@.C -o $@ miner_states.o

miner_states.o: miner_states.H miner_states.C
	$(CXX) -c $(INCLUDE) miner_states.C

clean:
	$(RM) *~ *.o test-singleton test-statemachine
