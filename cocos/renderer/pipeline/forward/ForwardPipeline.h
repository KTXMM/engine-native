#pragma once

#include "../RenderPipeline.h"

namespace cc {
namespace pipeline {
struct Light;
class UBOGlobal;

class CC_DLL ForwardPipeline : public RenderPipeline {
public:
    ForwardPipeline();
    ~ForwardPipeline();

    virtual bool initialize(const RenderPipelineInfo *info) override;
    virtual void destroy() override;
    virtual bool activate() override;

    void updateUBOs(RenderView *view);

    gfx::RenderPass *getOrCreateRenderPass(gfx::ClearFlags clearFlags);

    CC_INLINE gfx::Buffer *getLightsUBO() const { return _lightsUBO; }
    CC_INLINE const LightList &getValidLights() const { return _validLights; }
    CC_INLINE const gfx::BufferList &getLightBuffers() const { return _lightBuffers; }
    CC_INLINE const UintList &getLightIndexOffsets() const { return _lightIndexOffsets; }
    CC_INLINE const UintList &getLightIndices() const { return _lightIndices; }
    CC_INLINE const RenderObjectList &getRenderObjects() const { return _renderObjects; }
    CC_INLINE const gfx::CommandBufferList &getCommandBuffers() const { return _commandBuffers; }
    CC_INLINE float getShadingScale() const { return _shadingScale; }
    CC_INLINE float getFpScale() const { return _fpScale; }
    CC_INLINE bool isHDR() const { return _isHDR; }

private:
    //    void cullLightPerModel(cc::Model *model);
    bool activeRenderer();
    void destroyUBOs();

private:
    gfx::Buffer *_lightsUBO = nullptr;
    LightList _validLights;
    gfx::BufferList _lightBuffers;
    UintList _lightIndexOffsets;
    UintList _lightIndices;
    RenderObjectList _renderObjects;
    map<gfx::ClearFlags, gfx::RenderPass *> _renderPasses;
    UBOGlobal _uboGlobal;

    float _shadingScale = 1.0f;
    bool _isHDR = false;
    float _fpScale = 1.0f / 1024.0f;
};

} // namespace pipeline
} // namespace cc
