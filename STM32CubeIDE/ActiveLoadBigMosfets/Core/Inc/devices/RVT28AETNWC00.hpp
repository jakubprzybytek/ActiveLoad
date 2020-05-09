#ifndef INC_DEVICES_RVT28AETNWC00_HPP_
#define INC_DEVICES_RVT28AETNWC00_HPP_

class RVT28AETNWC00 {

private:

public:
	RVT28AETNWC00()  {}

	void init();

	void writeCommand(uint8_t command);
	void writeData(uint16_t data);

};

#endif /* INC_DEVICES_RVT28AETNWC00_HPP_ */
