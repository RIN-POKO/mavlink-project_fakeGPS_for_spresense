#include "GPS.h"

uint8_t AutoGenMesgBuff[1204];

MsgQueDef MsgqPoolDefs[NUM_MSGQ_POOLS] =
    {
        /* n_drm, n_size, n_num, h_drm, h_size, h_num */

        {0x00000000, 0, 0, 0x00000000, 0, 0, 0},                    /* MSGQ_NULL */
        {(drm_t)AutoGenMesgBuff + 0xcc, 100, 5, 0xffffffff, 0, 0},  /* MSGQ_MAVLINK */
        {(drm_t)AutoGenMesgBuff + 0x2c0, 100, 5, 0xffffffff, 0, 0}, /* MSGQ_GPS */
};

GPS_class::GPS_class()
{
  send_id = MSGQ_MAVLINK; // Assign ID that be sent to a variable "send_id".
  ret_id = MSGQ_GPS;      // Assign ID that will return to a variable "self_id".
  msg_type = MSG_TYPE_RESPONSE;
}

void GPS_class::set()
{
  gps_input.time_usec = 0; // not set

  gps_input.lat = 351523041;
  gps_input.lon = 1369686962;

  gps_input.alt = 0; // not used

  gps_input.eph = UINT16_MAX; /// not used
  gps_input.epv = UINT16_MAX; // not used
  gps_input.vel = UINT16_MAX; // not used

  gps_input.vn = 0;
  gps_input.ve = 0;
  gps_input.vd = 0;

  gps_input.cog = UINT16_MAX; // not used

  gps_input.fix_type = 3; // gpsの動作状況の設定 0-1: no fix, 2: 2D fix, 3: 3D fix
  gps_input.satellites_visible = 1;
}

void GPS_class::send()
{
  // receceve request message
  err_t err = MsgLib::referMsgQueBlock(ret_id, &que);
  err = que->recv(TIME_FOREVER, &msg);
  if (msg->getType() == msg_type)
  {                                                  // Check that the message type is as expected or not.
    message_t message = msg->moveParam<message_t>(); // get an instance of type Object from Message packet.
    printf("receive_msg: %d\n", message.num);
    err = MsgLib::send<mavlink_hil_gps_t>(send_id, MsgPriNormal, msg_type, ret_id, gps_input);
    if (err != ERR_OK)
    {
      printf("send error: %x\n", err);
    }
    printf("send OK");

    err = que->pop(); // Release the message block.
  }
}

int main(int argc, FAR char *argv[])
{

  // 初期化
  err_t err = MsgLib::initFirst(NUM_MSGQ_POOLS, MSGQ_TOP_DRM);
  if (err != ERR_OK && err != ERR_STS)
  {
    printf("MsgLib::initFirst error: %x\n", err);
    return 1; // 初期化エラーの場合、終了する
  }

  while (ERR_OK != MsgLib::initPerCpu())
  {
    printf("MsgLib::initPerCpu error: retrying...\n");
    usleep(1000 * 1000); // 一定時間待ってから再試行
  }
  printf("sender_init:OK\n");
  while (ERR_OK != MsgLib::initPerCpu())
    ;

  GPS_class gps;

  while (1)
  {
    gps.set();
    gps.send();
  }
  return 0;
}
