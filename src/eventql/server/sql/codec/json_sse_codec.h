/**
 * Copyright (c) 2016 DeepCortex GmbH <legal@eventql.io>
 * Authors:
 *   - Paul Asmuth <paul@eventql.io>
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License ("the license") as
 * published by the Free Software Foundation, either version 3 of the License,
 * or any later version.
 *
 * In accordance with Section 7(e) of the license, the licensing of the Program
 * under the license does not imply a trademark license. Therefore any rights,
 * title and interest in our trademarks remain entirely with us.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You can be released from the requirements of the license by purchasing a
 * commercial license. Buying such a license is mandatory as soon as you develop
 * commercial activities involving this program without disclosing the source
 * code of your own applications
 */
#pragma once
#include <eventql/util/stdtypes.h>
#include <eventql/util/http/HTTPSSEStream.h>
#include <eventql/server/sql/codec/json_codec.h>
#include <eventql/sql/result_list.h>

namespace eventql {

class JSONSSECodec{
public:

  JSONSSECodec(RefPtr<http::HTTPSSEStream> sse_stream);

  void sendResults(const Vector<csql::ResultList>& results);
  void sendProgress(
      bool done,
      double progress,
      size_t tasks_total,
      size_t tasks_complete,
      size_t tasks_running,
      size_t tasks_failed);

protected:

  RefPtr<http::HTTPSSEStream> output_;
};

}
