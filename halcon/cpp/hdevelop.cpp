///////////////////////////////////////////////////////////////////////////////
// File generated by HDevelop for HALCON/C++ Version 18.11.0.1
// Non-ASCII strings in this file are encoded in UTF-8.
// 
// Please note that non-ASCII characters in string constants are exported
// as octal codes in order to guarantee that the strings are correctly
// created on all systems, independent on any compiler settings.
// 
// Source files with different encoding should not be mixed in one project.
///////////////////////////////////////////////////////////////////////////////



#ifndef __APPLE__
#  include "HalconCpp.h"
#  include "HDevThread.h"
#  if defined(__linux__) && (defined(__i386__) || defined(__x86_64__)) \
                         && !defined(NO_EXPORT_APP_MAIN)
#    include <X11/Xlib.h>
#  endif
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#    include <HALCONCpp/HDevThread.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#    include <HALCONCppxl/HDevThread.h>
#  endif
#  include <stdio.h>
#  include <HALCON/HpThread.h>
#  include <CoreFoundation/CFRunLoop.h>
#endif



using namespace HalconCpp;


#ifndef NO_EXPORT_MAIN
// Main procedure 
void action()
{

  // Local iconic variables
  HObject  ho_Image;

  // Local control variables
  HTuple  hv_AcqHandle, hv_CameraParameters, hv_CameraPose;
  HTuple  hv_AmplitudeThreshold, hv_RoiWidthLen2, hv_LineRowStart_Measure_01_0;
  HTuple  hv_LineColumnStart_Measure_01_0, hv_LineRowEnd_Measure_01_0;
  HTuple  hv_LineColumnEnd_Measure_01_0, hv_TmpCtrl_Row, hv_TmpCtrl_Column;
  HTuple  hv_TmpCtrl_Dr, hv_TmpCtrl_Dc, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1;
  HTuple  hv_TmpCtrl_Len2, hv_MsrHandle_Measure_01_0, hv_LineRowStart_Measure_01_1;
  HTuple  hv_LineColumnStart_Measure_01_1, hv_LineRowEnd_Measure_01_1;
  HTuple  hv_LineColumnEnd_Measure_01_1, hv_MsrHandle_Measure_01_1;
  HTuple  hv_LineRowStart_Measure_01_2, hv_LineColumnStart_Measure_01_2;
  HTuple  hv_LineRowEnd_Measure_01_2, hv_LineColumnEnd_Measure_01_2;
  HTuple  hv_MsrHandle_Measure_01_2, hv_LineRowStart_Measure_01_3;
  HTuple  hv_LineColumnStart_Measure_01_3, hv_LineRowEnd_Measure_01_3;
  HTuple  hv_LineColumnEnd_Measure_01_3, hv_MsrHandle_Measure_01_3;
  HTuple  hv_Row_Measure_01_0, hv_Column_Measure_01_0, hv_Amplitude_Measure_01_0;
  HTuple  hv_Distance_Measure_01_0, hv_Row_Measure_01_1, hv_Column_Measure_01_1;
  HTuple  hv_Amplitude_Measure_01_1, hv_Distance_Measure_01_1;
  HTuple  hv_Row_Measure_01_2, hv_Column_Measure_01_2, hv_Amplitude_Measure_01_2;
  HTuple  hv_Distance_Measure_01_2, hv_Row_Measure_01_3, hv_Column_Measure_01_3;
  HTuple  hv_Amplitude_Measure_01_3, hv_Distance_Measure_01_3;
  HTuple  hv_Column_World_Measure_01_0, hv_Row_World_Measure_01_0;
  HTuple  hv_TmpCtrl_Length, hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom;
  HTuple  hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo, hv_Distance_World_Measure_01_0;
  HTuple  hv_Column_World_Measure_01_1, hv_Row_World_Measure_01_1;
  HTuple  hv_Distance_World_Measure_01_1, hv_Column_World_Measure_01_2;
  HTuple  hv_Row_World_Measure_01_2, hv_Distance_World_Measure_01_2;
  HTuple  hv_Column_World_Measure_01_3, hv_Row_World_Measure_01_3;
  HTuple  hv_Distance_World_Measure_01_3;

  //Measure 01: Code generated by Measure 01
  //Measure 01: Initialize acquisition
  OpenFramegrabber("GigEVision2", 0, 0, 0, 0, 0, 0, "progressive", -1, "default", 
      -1, "false", "default", "d47c443017eb_OMRONSENTECH_STCMBA503POE", 0, -1, &hv_AcqHandle);
  //Measure 01: Initialize calibration
  hv_CameraParameters.Clear();
  hv_CameraParameters[0] = "area_scan_division";
  hv_CameraParameters[1] = 1.37727;
  hv_CameraParameters[2] = 31.7944;
  hv_CameraParameters[3] = 2.1972e-006;
  hv_CameraParameters[4] = 2.2e-006;
  hv_CameraParameters[5] = 361.524;
  hv_CameraParameters[6] = -499.362;
  hv_CameraParameters[7] = 2592;
  hv_CameraParameters[8] = 1944;
  hv_CameraPose.Clear();
  hv_CameraPose[0] = 0.00989773;
  hv_CameraPose[1] = 0.0163173;
  hv_CameraPose[2] = 6.86213;
  hv_CameraPose[3] = 358.601;
  hv_CameraPose[4] = 3.04897;
  hv_CameraPose[5] = 359.151;
  hv_CameraPose[6] = 0;
  //Measure 01: Prepare measurement
  hv_AmplitudeThreshold = 40;
  hv_RoiWidthLen2 = 5;
  SetSystem("int_zooming", "true");
  //Measure 01: Coordinates for line Measure 01 [0]
  hv_LineRowStart_Measure_01_0 = 283.283;
  hv_LineColumnStart_Measure_01_0 = 918.513;
  hv_LineRowEnd_Measure_01_0 = 500.794;
  hv_LineColumnEnd_Measure_01_0 = 1144.36;
  //Measure 01: Convert coordinates to rectangle2 type
  hv_TmpCtrl_Row = 0.5*(hv_LineRowStart_Measure_01_0+hv_LineRowEnd_Measure_01_0);
  hv_TmpCtrl_Column = 0.5*(hv_LineColumnStart_Measure_01_0+hv_LineColumnEnd_Measure_01_0);
  hv_TmpCtrl_Dr = hv_LineRowStart_Measure_01_0-hv_LineRowEnd_Measure_01_0;
  hv_TmpCtrl_Dc = hv_LineColumnEnd_Measure_01_0-hv_LineColumnStart_Measure_01_0;
  hv_TmpCtrl_Phi = hv_TmpCtrl_Dr.TupleAtan2(hv_TmpCtrl_Dc);
  hv_TmpCtrl_Len1 = 0.5*(((hv_TmpCtrl_Dr*hv_TmpCtrl_Dr)+(hv_TmpCtrl_Dc*hv_TmpCtrl_Dc)).TupleSqrt());
  hv_TmpCtrl_Len2 = hv_RoiWidthLen2;
  //Measure 01: Create measure for line Measure 01 [0]
  //Measure 01: Attention: This assumes all images have the same size!
  GenMeasureRectangle2(hv_TmpCtrl_Row, hv_TmpCtrl_Column, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1, 
      hv_TmpCtrl_Len2, 2592, 1944, "nearest_neighbor", &hv_MsrHandle_Measure_01_0);
  //Measure 01: Coordinates for line Measure 01 [1]
  hv_LineRowStart_Measure_01_1 = 279.885;
  hv_LineColumnStart_Measure_01_1 = 2002.57;
  hv_LineRowEnd_Measure_01_1 = 283.283;
  hv_LineColumnEnd_Measure_01_1 = 2478.58;
  //Measure 01: Convert coordinates to rectangle2 type
  hv_TmpCtrl_Row = 0.5*(hv_LineRowStart_Measure_01_1+hv_LineRowEnd_Measure_01_1);
  hv_TmpCtrl_Column = 0.5*(hv_LineColumnStart_Measure_01_1+hv_LineColumnEnd_Measure_01_1);
  hv_TmpCtrl_Dr = hv_LineRowStart_Measure_01_1-hv_LineRowEnd_Measure_01_1;
  hv_TmpCtrl_Dc = hv_LineColumnEnd_Measure_01_1-hv_LineColumnStart_Measure_01_1;
  hv_TmpCtrl_Phi = hv_TmpCtrl_Dr.TupleAtan2(hv_TmpCtrl_Dc);
  hv_TmpCtrl_Len1 = 0.5*(((hv_TmpCtrl_Dr*hv_TmpCtrl_Dr)+(hv_TmpCtrl_Dc*hv_TmpCtrl_Dc)).TupleSqrt());
  hv_TmpCtrl_Len2 = hv_RoiWidthLen2;
  //Measure 01: Create measure for line Measure 01 [1]
  //Measure 01: Attention: This assumes all images have the same size!
  GenMeasureRectangle2(hv_TmpCtrl_Row, hv_TmpCtrl_Column, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1, 
      hv_TmpCtrl_Len2, 2592, 1944, "nearest_neighbor", &hv_MsrHandle_Measure_01_1);
  //Measure 01: Coordinates for line Measure 01 [2]
  hv_LineRowStart_Measure_01_2 = 1374.23;
  hv_LineColumnStart_Measure_01_2 = 939.361;
  hv_LineRowEnd_Measure_01_2 = 1567.95;
  hv_LineColumnEnd_Measure_01_2 = 1120.04;
  //Measure 01: Convert coordinates to rectangle2 type
  hv_TmpCtrl_Row = 0.5*(hv_LineRowStart_Measure_01_2+hv_LineRowEnd_Measure_01_2);
  hv_TmpCtrl_Column = 0.5*(hv_LineColumnStart_Measure_01_2+hv_LineColumnEnd_Measure_01_2);
  hv_TmpCtrl_Dr = hv_LineRowStart_Measure_01_2-hv_LineRowEnd_Measure_01_2;
  hv_TmpCtrl_Dc = hv_LineColumnEnd_Measure_01_2-hv_LineColumnStart_Measure_01_2;
  hv_TmpCtrl_Phi = hv_TmpCtrl_Dr.TupleAtan2(hv_TmpCtrl_Dc);
  hv_TmpCtrl_Len1 = 0.5*(((hv_TmpCtrl_Dr*hv_TmpCtrl_Dr)+(hv_TmpCtrl_Dc*hv_TmpCtrl_Dc)).TupleSqrt());
  hv_TmpCtrl_Len2 = hv_RoiWidthLen2;
  //Measure 01: Create measure for line Measure 01 [2]
  //Measure 01: Attention: This assumes all images have the same size!
  GenMeasureRectangle2(hv_TmpCtrl_Row, hv_TmpCtrl_Column, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1, 
      hv_TmpCtrl_Len2, 2592, 1944, "nearest_neighbor", &hv_MsrHandle_Measure_01_2);
  //Measure 01: Coordinates for line Measure 01 [3]
  hv_LineRowStart_Measure_01_3 = 1476.19;
  hv_LineColumnStart_Measure_01_3 = 1304.19;
  hv_LineRowEnd_Measure_01_3 = 1771.87;
  hv_LineColumnEnd_Measure_01_3 = 1314.61;
  //Measure 01: Convert coordinates to rectangle2 type
  hv_TmpCtrl_Row = 0.5*(hv_LineRowStart_Measure_01_3+hv_LineRowEnd_Measure_01_3);
  hv_TmpCtrl_Column = 0.5*(hv_LineColumnStart_Measure_01_3+hv_LineColumnEnd_Measure_01_3);
  hv_TmpCtrl_Dr = hv_LineRowStart_Measure_01_3-hv_LineRowEnd_Measure_01_3;
  hv_TmpCtrl_Dc = hv_LineColumnEnd_Measure_01_3-hv_LineColumnStart_Measure_01_3;
  hv_TmpCtrl_Phi = hv_TmpCtrl_Dr.TupleAtan2(hv_TmpCtrl_Dc);
  hv_TmpCtrl_Len1 = 0.5*(((hv_TmpCtrl_Dr*hv_TmpCtrl_Dr)+(hv_TmpCtrl_Dc*hv_TmpCtrl_Dc)).TupleSqrt());
  hv_TmpCtrl_Len2 = hv_RoiWidthLen2;
  //Measure 01: Create measure for line Measure 01 [3]
  //Measure 01: Attention: This assumes all images have the same size!
  GenMeasureRectangle2(hv_TmpCtrl_Row, hv_TmpCtrl_Column, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1, 
      hv_TmpCtrl_Len2, 2592, 1944, "nearest_neighbor", &hv_MsrHandle_Measure_01_3);
  while (0 != 1)
  {
    //Measure 01: Acquire image
    GrabImage(&ho_Image, hv_AcqHandle);
    //Measure 01: Execute measurements
    MeasurePos(ho_Image, hv_MsrHandle_Measure_01_0, 1, hv_AmplitudeThreshold, "all", 
        "all", &hv_Row_Measure_01_0, &hv_Column_Measure_01_0, &hv_Amplitude_Measure_01_0, 
        &hv_Distance_Measure_01_0);
    MeasurePos(ho_Image, hv_MsrHandle_Measure_01_1, 1, hv_AmplitudeThreshold, "all", 
        "all", &hv_Row_Measure_01_1, &hv_Column_Measure_01_1, &hv_Amplitude_Measure_01_1, 
        &hv_Distance_Measure_01_1);
    MeasurePos(ho_Image, hv_MsrHandle_Measure_01_2, 1, hv_AmplitudeThreshold, "all", 
        "all", &hv_Row_Measure_01_2, &hv_Column_Measure_01_2, &hv_Amplitude_Measure_01_2, 
        &hv_Distance_Measure_01_2);
    MeasurePos(ho_Image, hv_MsrHandle_Measure_01_3, 1, hv_AmplitudeThreshold, "all", 
        "all", &hv_Row_Measure_01_3, &hv_Column_Measure_01_3, &hv_Amplitude_Measure_01_3, 
        &hv_Distance_Measure_01_3);
    //Measure 01: Transform to world coordinates
    //Measure 01: Calibrate positions for Measure 01 [0]
    ImagePointsToWorldPlane(hv_CameraParameters, hv_CameraPose, hv_Row_Measure_01_0, 
        hv_Column_Measure_01_0, 0.001, &hv_Column_World_Measure_01_0, &hv_Row_World_Measure_01_0);
    //Measure 01: Calibrate distances
    hv_TmpCtrl_Length = hv_Row_World_Measure_01_0.TupleLength();
    if (0 != (hv_TmpCtrl_Length>0))
    {
      TupleSelectRange(hv_Row_World_Measure_01_0, 0, hv_TmpCtrl_Length-2, &hv_TmpCtrl_RowFrom);
      TupleSelectRange(hv_Column_World_Measure_01_0, 0, hv_TmpCtrl_Length-2, &hv_TmpCtrl_ColumnFrom);
      TupleSelectRange(hv_Row_World_Measure_01_0, 1, hv_TmpCtrl_Length-1, &hv_TmpCtrl_RowTo);
      TupleSelectRange(hv_Column_World_Measure_01_0, 1, hv_TmpCtrl_Length-1, &hv_TmpCtrl_ColumnTo);
      DistancePp(hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom, hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo, 
          &hv_Distance_World_Measure_01_0);
    }
    //Measure 01: Calibrate positions for Measure 01 [1]
    ImagePointsToWorldPlane(hv_CameraParameters, hv_CameraPose, hv_Row_Measure_01_1, 
        hv_Column_Measure_01_1, 0.001, &hv_Column_World_Measure_01_1, &hv_Row_World_Measure_01_1);
    //Measure 01: Calibrate distances
    hv_TmpCtrl_Length = hv_Row_World_Measure_01_1.TupleLength();
    if (0 != (hv_TmpCtrl_Length>0))
    {
      TupleSelectRange(hv_Row_World_Measure_01_1, 0, hv_TmpCtrl_Length-2, &hv_TmpCtrl_RowFrom);
      TupleSelectRange(hv_Column_World_Measure_01_1, 0, hv_TmpCtrl_Length-2, &hv_TmpCtrl_ColumnFrom);
      TupleSelectRange(hv_Row_World_Measure_01_1, 1, hv_TmpCtrl_Length-1, &hv_TmpCtrl_RowTo);
      TupleSelectRange(hv_Column_World_Measure_01_1, 1, hv_TmpCtrl_Length-1, &hv_TmpCtrl_ColumnTo);
      DistancePp(hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom, hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo, 
          &hv_Distance_World_Measure_01_1);
    }
    //Measure 01: Calibrate positions for Measure 01 [2]
    ImagePointsToWorldPlane(hv_CameraParameters, hv_CameraPose, hv_Row_Measure_01_2, 
        hv_Column_Measure_01_2, 0.001, &hv_Column_World_Measure_01_2, &hv_Row_World_Measure_01_2);
    //Measure 01: Calibrate distances
    hv_TmpCtrl_Length = hv_Row_World_Measure_01_2.TupleLength();
    if (0 != (hv_TmpCtrl_Length>0))
    {
      TupleSelectRange(hv_Row_World_Measure_01_2, 0, hv_TmpCtrl_Length-2, &hv_TmpCtrl_RowFrom);
      TupleSelectRange(hv_Column_World_Measure_01_2, 0, hv_TmpCtrl_Length-2, &hv_TmpCtrl_ColumnFrom);
      TupleSelectRange(hv_Row_World_Measure_01_2, 1, hv_TmpCtrl_Length-1, &hv_TmpCtrl_RowTo);
      TupleSelectRange(hv_Column_World_Measure_01_2, 1, hv_TmpCtrl_Length-1, &hv_TmpCtrl_ColumnTo);
      DistancePp(hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom, hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo, 
          &hv_Distance_World_Measure_01_2);
    }
    //Measure 01: Calibrate positions for Measure 01 [3]
    ImagePointsToWorldPlane(hv_CameraParameters, hv_CameraPose, hv_Row_Measure_01_3, 
        hv_Column_Measure_01_3, 0.001, &hv_Column_World_Measure_01_3, &hv_Row_World_Measure_01_3);
    //Measure 01: Calibrate distances
    hv_TmpCtrl_Length = hv_Row_World_Measure_01_3.TupleLength();
    if (0 != (hv_TmpCtrl_Length>0))
    {
      TupleSelectRange(hv_Row_World_Measure_01_3, 0, hv_TmpCtrl_Length-2, &hv_TmpCtrl_RowFrom);
      TupleSelectRange(hv_Column_World_Measure_01_3, 0, hv_TmpCtrl_Length-2, &hv_TmpCtrl_ColumnFrom);
      TupleSelectRange(hv_Row_World_Measure_01_3, 1, hv_TmpCtrl_Length-1, &hv_TmpCtrl_RowTo);
      TupleSelectRange(hv_Column_World_Measure_01_3, 1, hv_TmpCtrl_Length-1, &hv_TmpCtrl_ColumnTo);
      DistancePp(hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom, hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo, 
          &hv_Distance_World_Measure_01_3);
    }
    //Measure 01: Do something with the results
  }
}


#ifndef NO_EXPORT_APP_MAIN

#ifdef __APPLE__
// On OS X systems, we must have a CFRunLoop running on the main thread in
// order for the HALCON graphics operators to work correctly, and run the
// action function in a separate thread. A CFRunLoopTimer is used to make sure
// the action function is not called before the CFRunLoop is running.
// Note that starting with macOS 10.12, the run loop may be stopped when a
// window is closed, so we need to put the call to CFRunLoopRun() into a loop
// of its own.
HTuple      gStartMutex;
H_pthread_t gActionThread;
HBOOL       gTerminate = FALSE;

static void timer_callback(CFRunLoopTimerRef timer, void *info)
{
  UnlockMutex(gStartMutex);
}

static Herror apple_action(void **parameters)
{
  // Wait until the timer has fired to start processing.
  LockMutex(gStartMutex);
  UnlockMutex(gStartMutex);

  try
  {
    action();
  }
  catch (HException &exception)
  {
    fprintf(stderr,"  Error #%u in %s: %s\n", exception.ErrorCode(),
            (const char *)exception.ProcName(),
            (const char *)exception.ErrorMessage());
  }

  // Tell the main thread to terminate itself.
  LockMutex(gStartMutex);
  gTerminate = TRUE;
  UnlockMutex(gStartMutex);
  CFRunLoopStop(CFRunLoopGetMain());
  return H_MSG_OK;
}

static int apple_main(int argc, char *argv[])
{
  Herror                error;
  CFRunLoopTimerRef     Timer;
  CFRunLoopTimerContext TimerContext = { 0, 0, 0, 0, 0 };

  CreateMutex("type","sleep",&gStartMutex);
  LockMutex(gStartMutex);

  error = HpThreadHandleAlloc(&gActionThread);
  if (H_MSG_OK != error)
  {
    fprintf(stderr,"HpThreadHandleAlloc failed: %d\n", error);
    exit(1);
  }

  error = HpThreadCreate(gActionThread,0,apple_action);
  if (H_MSG_OK != error)
  {
    fprintf(stderr,"HpThreadCreate failed: %d\n", error);
    exit(1);
  }

  Timer = CFRunLoopTimerCreate(kCFAllocatorDefault,
                               CFAbsoluteTimeGetCurrent(),0,0,0,
                               timer_callback,&TimerContext);
  if (!Timer)
  {
    fprintf(stderr,"CFRunLoopTimerCreate failed\n");
    exit(1);
  }
  CFRunLoopAddTimer(CFRunLoopGetCurrent(),Timer,kCFRunLoopCommonModes);

  for (;;)
  {
    HBOOL terminate;

    CFRunLoopRun();

    LockMutex(gStartMutex);
    terminate = gTerminate;
    UnlockMutex(gStartMutex);

    if (terminate)
      break;
  }

  CFRunLoopRemoveTimer(CFRunLoopGetCurrent(),Timer,kCFRunLoopCommonModes);
  CFRelease(Timer);

  error = HpThreadHandleFree(gActionThread);
  if (H_MSG_OK != error)
  {
    fprintf(stderr,"HpThreadHandleFree failed: %d\n", error);
    exit(1);
  }

  ClearMutex(gStartMutex);
  return 0;
}
#endif

int main(int argc, char *argv[])
{
  int ret = 0;

  try
  {
#if defined(_WIN32)
    SetSystem("use_window_thread", "true");
#elif defined(__linux__) && (defined(__i386__) || defined(__x86_64__))
    XInitThreads();
#endif

    // Default settings used in HDevelop (can be omitted)
    SetSystem("width", 512);
    SetSystem("height", 512);

#ifndef __APPLE__
    action();
#else
    ret = apple_main(argc,argv);
#endif
  }
  catch (HException &exception)
  {
    fprintf(stderr,"  Error #%u in %s: %s\n", exception.ErrorCode(),
            (const char *)exception.ProcName(),
            (const char *)exception.ErrorMessage());
    ret = 1;
  }
  return ret;
}

#endif


#endif

