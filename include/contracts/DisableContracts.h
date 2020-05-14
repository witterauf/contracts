#ifndef __LEAVE_CONTRACTS__
#ifdef __CONTRACTS_ENABLED__
#undef STRINGIFY_HELPER
#undef TOSTRING
#undef Expects
#undef Ensures
#undef Assert
#undef AssertWithMessage
#undef InvalidCase
#undef __CONTRACTS_ENABLED__
#endif
#endif