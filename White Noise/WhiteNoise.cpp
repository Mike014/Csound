#include <csound/csound.hpp>
#include <iostream>

int main() {
    Csound csound;

    // Codice Csound completo
    const char* csd = R"(
<CsoundSynthesizer>
<CsOptions>
</CsOptions>
<CsInstruments>

sr = 44100
kr = 4410
ksmps = 10
nchnls = 1

// Orchestra
instr 1
    asuono rand 10000
    out asuono
endin

</CsInstruments>
<CsScore>
i1 0 10
</CsScore>
</CsoundSynthesizer>
    )";

    // Inizializzazione di Csound
    csound.SetOption("-odac");
    csound.CompileCsdText(csd);
    csound.Start();

    // Esecuzione di Csound
    while (!csound.PerformKsmps()) {}

    // Pulizia di Csound
    csound.Stop();
    csound.Cleanup();

    return 0;
}







