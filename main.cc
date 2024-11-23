#include <iostream>

#include "leftover_tracker_backend.h"
#include "server_utils/crow_all.h"
#include "server_utils/sessions.h"

int main() {
  std::string kFilename = "data/leftover_records.json";
  LeftoverTrackerBackend backend{kFilename};
  backend.LoadRecordsFromJSONFile();

  crow::App<crow::CORSHandler> app;

  auto &cors_middleware = app.get_middleware<crow::CORSHandler>();
  cors_middleware.global().origin("*");
  cors_middleware.global().max_age(7200);

  CROW_ROUTE(app, "/get_records")
  ([&](const crow::request &req) { return backend.GetRecords(); });

  CROW_ROUTE(app, "/add_record")
  ([&](const crow::request &req) { return backend.AddRecord(req.url_params); });

  CROW_ROUTE(app, "/delete_record")
  ([&](const crow::request &req) {
    return backend.DeleteRecord(req.url_params);
  });

  CROW_ROUTE(app, "/get_leftover_report")
  ([&](const crow::request &req) { return backend.GetLeftoverReport(); });

  CROW_ROUTE(app, "/backup_to_disk")
  ([&](const crow::request &req) {
    crow::json::wvalue status;
    status["success"] = backend.WriteRecordsToJSONFile();
    return status;
  });

  CROW_ROUTE(app, "/")
  ([](crow::response &res) {
    res.set_static_file_info("html/index.html");
    res.end();
  });

  app.port(18080).concurrency(1).run();
  return 0;
}