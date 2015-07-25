// This file is part of the "libcortex" project
//   (c) 2009-2015 Christian Parpart <https://github.com/christianparpart>
//   (c) 2014-2015 Paul Asmuth <https://github.com/paulasmuth>
//
// libcortex is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License v3.0.
// You should have received a copy of the GNU Affero General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cortex-base/Api.h>
#include <cortex-base/executor/SafeCall.h>
#include <cortex-base/sysconfig.h>

#include <exception>
#include <deque>
#include <functional>
#include <string>

namespace cortex {

/**
 * Closure Execution Service API.
 *
 * Defines an interface for executing tasks. The implementer
 * can distinguish in different execution models, such as threading,
 * sequential or inline execution.
 *
 * @see DirectExecutor
 * @see ThreadPool
 */
class CORTEX_API Executor : protected SafeCall {
 public:
  explicit Executor(std::function<void(const std::exception&)> eh);
  virtual ~Executor();

  typedef std::function<void()> Task;

  using SafeCall::setExceptionHandler;

  /**
   * Executes given task.
   */
  virtual void execute(Task task) = 0;

  /**
   * Retrieves a human readable name of this executor (for introspection only).
   */
  virtual std::string toString() const = 0;
};

} // namespace cortex
