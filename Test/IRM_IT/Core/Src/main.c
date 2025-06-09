/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == IRM_1_Pin)
  {
    HAL_UART_Transmit(&huart2, "1", sizeof("1"), 1000);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
  }
  if (GPIO_Pin == IRM_2_Pin)
  {
    HAL_UART_Transmit(&huart2, "2", sizeof("2"), 1000);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
  }
  if (GPIO_Pin == IRM_3_Pin)
  {
    HAL_UART_Transmit(&huart2, "3", sizeof("3"), 1000);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
  }
  if (GPIO_Pin == IRM_4_Pin)
  {
    HAL_UART_Transmit(&huart2, "4", sizeof("4"), 1000);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
  }
  if (GPIO_Pin == IRM_5_Pin)
  {
    HAL_UART_Transmit(&huart2, "5", sizeof("5"), 1000);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
  }
  if (GPIO_Pin == IRM_6_Pin)
  {
    HAL_UART_Transmit(&huart2, "6", sizeof("6"), 1000);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
  }
  if (GPIO_Pin == IRM_7_Pin)
  {
    HAL_UART_Transmit(&huart2, "7", sizeof("7"), 1000);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
  }
  if (GPIO_Pin == IRM_8_Pin)
  {
    HAL_UART_Transmit(&huart2, "8", sizeof("8"), 1000);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
  }
  if (GPIO_Pin == IRM_9_Pin)
  {
    HAL_UART_Transmit(&huart2, "9", sizeof("9"), 1000);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
  }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_UART_Transmit(&huart2, (uint8_t*) "REBOOT", sizeof("REBOOT"), 1000);
  while (1)
  {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // Toggle the LED on PC13
    HAL_Delay(500); // Delay for 500 ms to see the toggle effect
    

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
