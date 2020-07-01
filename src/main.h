//  __ __  __   __  __   __   __
// |_ (__ |__) (__)  _) /__  /__
// |__ __)|    (__) /__ \__) \__)
//
// (C) Copyright 2020 Adam K Dean

void connect_to_wifi();
void blink(int count, int on, int off);
float getAvgTemperature(int samples, int interval, float adjustment);
const char* wl_status_to_string(wl_status_t status);
