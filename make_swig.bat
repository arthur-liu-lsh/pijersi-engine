@echo off
swig -csharp -c++ -Iinclude -namespace PijersiEngine -outdir wrap -o src/pijersi_engine_wrap.cxx pijersi_engine.i