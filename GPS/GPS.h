// ------------------------------------------------------------------------------
//   Includes
// ------------------------------------------------------------------------------

#include <stdio.h>
#include <memutils/message/Message.h>
#include "../include/msgq_id.h"
#include "../include/msgq_pool.h"

#include "../include/mavlink/v2.0/common/mavlink.h"

using std::string;
using namespace std;

// ------------------------------------------------------------------------------
//   Prototypes
// ------------------------------------------------------------------------------

extern "C" int main(int argc, char **argv);

class GPS_class
{
public:
	void set();
	void send();
	GPS_class();

private:
	mavlink_hil_gps_t gps_input;
	MsgQueId send_id;
	MsgQueId ret_id;
	MSG_TYPE msg_type;
	MsgQueBlock *que;
	MsgPacket *msg;
};

struct message_t
{
	int num;
};