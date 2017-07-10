//
// Key.cpp for  in /home/bourre_a/Semestre_4/cpp/cpp_indie_studio/src
//
// Made by Bourreau Quentin
// Login   <quentin.bourreau@epitech.eu>
//
// Started on  Wed Jun 21 19:59:18 2017 Bourreau Quentin
// Last update Wed Jun 21 20:16:12 2017 Bourreau Quentin
//

# include "Key.hh"

EKEY_CODE	ret_key_down(EventReceiver receiver)
{
  if (receiver.IsKeyDown(KEY_KEY_A))
    return (KEY_KEY_A);
  if (receiver.IsKeyDown(KEY_KEY_B))
    return (KEY_KEY_B);
  if (receiver.IsKeyDown(KEY_KEY_C))
    return (KEY_KEY_C);
  if (receiver.IsKeyDown(KEY_KEY_D))
    return (KEY_KEY_D);
  if (receiver.IsKeyDown(KEY_KEY_E))
    return (KEY_KEY_E);
  if (receiver.IsKeyDown(KEY_KEY_F))
    return (KEY_KEY_F);
  if (receiver.IsKeyDown(KEY_KEY_G))
    return (KEY_KEY_G);
  if (receiver.IsKeyDown(KEY_KEY_H))
    return (KEY_KEY_H);
  if (receiver.IsKeyDown(KEY_KEY_I))
    return (KEY_KEY_I);
  if (receiver.IsKeyDown(KEY_KEY_J))
    return (KEY_KEY_J);
  if (receiver.IsKeyDown(KEY_KEY_K))
    return (KEY_KEY_K);
  if (receiver.IsKeyDown(KEY_KEY_L))
    return (KEY_KEY_L);
  if (receiver.IsKeyDown(KEY_KEY_M))
    return (KEY_KEY_M);
  if (receiver.IsKeyDown(KEY_KEY_N))
    return (KEY_KEY_N);
  if (receiver.IsKeyDown(KEY_KEY_O))
    return (KEY_KEY_O);
  if (receiver.IsKeyDown(KEY_KEY_P))
    return (KEY_KEY_P);
  if (receiver.IsKeyDown(KEY_KEY_Q))
    return (KEY_KEY_Q);
  if (receiver.IsKeyDown(KEY_KEY_R))
    return (KEY_KEY_R);
  if (receiver.IsKeyDown(KEY_KEY_S))
    return (KEY_KEY_S);
  if (receiver.IsKeyDown(KEY_KEY_T))
    return (KEY_KEY_T);
  if (receiver.IsKeyDown(KEY_KEY_U))
    return (KEY_KEY_U);
  if (receiver.IsKeyDown(KEY_KEY_V))
    return (KEY_KEY_V);
  if (receiver.IsKeyDown(KEY_KEY_W))
    return (KEY_KEY_W);
  if (receiver.IsKeyDown(KEY_KEY_X))
    return (KEY_KEY_X);
  if (receiver.IsKeyDown(KEY_KEY_Y))
    return (KEY_KEY_Y);
  if (receiver.IsKeyDown(KEY_KEY_Z))
    return (KEY_KEY_Z);
  if (receiver.IsKeyDown(KEY_SPACE))
    return (KEY_SPACE);
  if (receiver.IsKeyDown(KEY_RSHIFT))
    return (KEY_RSHIFT);
  if (receiver.IsKeyDown(KEY_UP))
    return (KEY_UP);
  if (receiver.IsKeyDown(KEY_DOWN))
    return (KEY_DOWN);
  if (receiver.IsKeyDown(KEY_LEFT))
    return (KEY_LEFT);
  if (receiver.IsKeyDown(KEY_RIGHT))
    return (KEY_RIGHT);
}
