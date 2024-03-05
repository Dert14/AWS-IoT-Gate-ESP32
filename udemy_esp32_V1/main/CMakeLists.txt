# Edit following two lines to set component requirements (see docs)
#idf_component_register(SRCS "main.c" "led_driver.cpp" "aws_connection.c"
#						INCLUDE_DIRS ".")

idf_component_register(SRCS "main.c" "aws_connection.c"
						INCLUDE_DIRS ".")

target_add_binary_data(${COMPONENT_TARGET} "certs/aws_root_ca_pem" TEXT)
target_add_binary_data(${COMPONENT_TARGET} "certs/certificate_pem_crt" TEXT)
target_add_binary_data(${COMPONENT_TARGET} "certs/private_pem_key" TEXT)
