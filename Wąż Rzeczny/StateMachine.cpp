#include "StateMachine.h"

namespace Brewque
{
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		if (isReplacing == 1 && !this->_states.empty())
		{
			this->_states.pop();
		}

		this->_states.push(std::move(newState));
		this->_states.top()->Init();
	}

	void StateMachine::RemoveState()
	{
		if (!this->_states.empty())
		{
			this->_states.pop();
		}
	}

	StateRef &StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}
