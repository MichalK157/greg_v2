#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "main.h"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	HAL_GPIO_TogglePin(GPIOJ, GPIO_PIN_13);

	if(HAL_GPIO_ReadPin(USER_GPIO_GPIO_Port, USER_GPIO_Pin) == GPIO_PIN_SET)
	{
		modelListener->updateScrean();
	}

}
