// RUN: %dxc -E main -T ps_5_0 %s

SamplerState samp1 : register(s5);
Texture2D<float4> text1 : register(t3);

float4 main(float2 a : A) : SV_Target
{
  uint status;
  float4 r = 0;
  r += text1.Sample(samp1, a);
  r += text1.Sample(samp1, a, uint2(-5, 7));
  r += text1.Sample(samp1, a, uint2(-4, 1), 0.5f);
  r += text1.Sample(samp1, a, uint2(-3, 2), 0.f, status); r += status;
  r += text1.Sample(samp1, a, uint2(-3, 2), a.x, status); r += status;
  return r;
}