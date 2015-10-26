/**
 * Copyright (c) 2015 - The CM Authors <legal@clickmatcher.com>
 *   All Rights Reserved.
 *
 * This file is CONFIDENTIAL -- Distribution or duplication of this material or
 * the information contained herein is strictly forbidden unless prior written
 * permission is obtained.
 */
#pragma once
#include "stx/stdtypes.h"
#include "zbase/mapreduce/MapReduceTask.h"
#include "zbase/core/TSDBService.h"
#include "zbase/AnalyticsAuth.h"

using namespace stx;

namespace zbase {

struct SaveToTableTaskShard : public MapReduceTaskShard {
  size_t shard;
};

class SaveToTableTask : public MapReduceTask {
public:

  SaveToTableTask(
      const AnalyticsSession& session,
      const String& table_name,
      Vector<RefPtr<MapReduceTask>> sources,
      MapReduceShardList* shards,
      AnalyticsAuth* auth,
      TSDBService* tsdb);

  Option<MapReduceShardResult> execute(
      RefPtr<MapReduceTaskShard> shard,
      RefPtr<MapReduceScheduler> job) override;

protected:
  AnalyticsSession session_;
  String table_name_;
  Vector<RefPtr<MapReduceTask>> sources_;
  AnalyticsAuth* auth_;
};

} // namespace zbase


