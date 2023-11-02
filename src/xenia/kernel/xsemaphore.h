/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_KERNEL_XSEMAPHORE_H_
#define XENIA_KERNEL_XSEMAPHORE_H_

#include "xenia/base/threading.h"
#include "xenia/kernel/xobject.h"
#include "xenia/kernel/kernel_guest_structures.h"
#include "xenia/kernel/xthread.h"
namespace xe {
namespace kernel {

class XSemaphore : public XObject {
 public:
  static const XObject::Type kObjectType = XObject::Type::Semaphore;

  explicit XSemaphore(KernelState* kernel_state);
  ~XSemaphore() override;

  [[nodiscard]] bool Initialize(int32_t initial_count, int32_t maximum_count);
  [[nodiscard]] bool InitializeNative(void* native_ptr,
                                      X_DISPATCH_HEADER* header);

  bool Save(ByteStream* stream) override;
  static object_ref<XSemaphore> Restore(KernelState* kernel_state,
                                        ByteStream* stream);

 protected:
  xe::threading::WaitHandle* GetWaitHandle() override {
    return nullptr;
  }

 private:
};

}  // namespace kernel
}  // namespace xe

#endif  // XENIA_KERNEL_XSEMAPHORE_H_
