#pragma once

#include <stack>
#include <memory>

#include "State.h"

namespace Brewque
{
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		StateMachine() { };
		~StateMachine() { };

		void AddState(StateRef newState, bool isReplacing);
		void RemoveState();

		StateRef &GetActiveState();

	private:
		std::stack <StateRef> _states;
	};
}